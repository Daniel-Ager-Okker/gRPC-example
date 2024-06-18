#include <grpcpp/create_channel.h>
#include <gtest/gtest.h>
#include <thread>

#include "MockStorageManager.h"
#include "TestClient.h"
#include <api/GrpcAPI.h>

using test_grpc_api::MockStorageManager;
using test_grpc_api::TestClient;

constexpr char SERVER_IP[] = "localhost:50051";

TEST(ServerSuite, RegistrateUser) {
    // 1.Run server
    std::shared_ptr<MockStorageManager> pDBManager = std::make_shared<MockStorageManager>();
    std::thread                         serverThread(api_grpc::runServer, SERVER_IP, pDBManager);

    std::shared_ptr<grpc::Channel> pChannel =
        grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials());

    test_grpc_api::TestClient client(pChannel);

    // 2.Add user
    auto [ok, reason] =
        client.registrateUser("someUser@mail.ru", "someUserName", "someuserSername", std::nullopt);
    ASSERT_EQ(true, ok);
    ASSERT_EQ("", reason);

    // 3.try to add user again
    std::tie(ok, reason) =
        client.registrateUser("someUser@mail.ru", "someUserName", "someuserSername", std::nullopt);
    ASSERT_EQ(false, ok);
    ASSERT_EQ("already have such e-mail", reason);

    // 4.Stop server
    api_grpc::stopServer();
    serverThread.join();
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}