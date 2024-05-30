#include <gtest/gtest.h>
#include <grpcpp/create_channel.h>

#include <api/GrpcAPI.h>
#include "TestClient.h"
#include "MockStorageManager.h"

using test_grpc_api::MockStorageManager;
using test_grpc_api::TestClient;

TEST(ServerSuite, RegistrateUser) {
    // 1.Run server
    std::unique_ptr<MockStorageManager> pDBManager = std::make_unique<>();

    std::shared_ptr<grpc::Channel> pChannel = grpc::CreateChannel(
        "localhost:50051",
        grpc::InsecureChannelCredentials()
    );

    test_grpc_api::TestClient client(pChannel);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}