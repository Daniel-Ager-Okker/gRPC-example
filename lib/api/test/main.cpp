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

    // 2.Create client
    std::shared_ptr<grpc::Channel> pChannel =
        grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials());

    test_grpc_api::TestClient client(pChannel);

    // 3.Add user
    auto [ok, reason] =
        client.registrateUser("someUser@mail.ru", "someUserName", "someuserSername", std::nullopt);
    ASSERT_EQ(true, ok);
    ASSERT_EQ("", reason);

    // 4.Try to add user again
    std::tie(ok, reason) =
        client.registrateUser("someUser@mail.ru", "someUserName", "someuserSername", std::nullopt);
    ASSERT_EQ(false, ok);
    ASSERT_EQ("already have such e-mail", reason);

    // 5.Stop server
    api_grpc::stopServer();
    serverThread.join();
}

TEST(ServerSuite, Subscribe) {
    // 1.Run server
    std::shared_ptr<MockStorageManager> pDBManager = std::make_shared<MockStorageManager>();
    std::thread                         serverThread(api_grpc::runServer, SERVER_IP, pDBManager);

    // 2.Create client
    std::shared_ptr<grpc::Channel> pChannel =
        grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials());

    test_grpc_api::TestClient client(pChannel);

    // 3.Add users
    client.registrateUser(
        "subscriber@mail.ru", "subscriberName", "subscriberSername", std::nullopt);
    client.registrateUser(
        "subscripton@mail.ru", "subscriptonName", "subscriptonSername", std::nullopt);

    // 3.Subscribe: invalid case 1
    auto [ok, reason] =
        client.subscribe("non-existing-user1@mail.ru", "non-existing-user2@mail.ru");
    ASSERT_EQ(false, ok);
    ASSERT_EQ("user is not registrated: non-existing-user1@mail.ru", reason);

    // 4.Subscribe: invalid case 2
    std::tie(ok, reason) = client.subscribe("subscriber@mail.ru", "non-existing-user2@mail.ru");
    ASSERT_EQ(false, ok);
    ASSERT_EQ("user is not registrated: non-existing-user2@mail.ru", reason);

    // 5.Subscribe: valid case
    std::tie(ok, reason) = client.subscribe("subscriber@mail.ru", "subscripton@mail.ru");
    ASSERT_EQ(true, ok);

    // 6.Subscribe: try again
    std::tie(ok, reason) = client.subscribe("subscriber@mail.ru", "subscripton@mail.ru");
    ASSERT_EQ(false, ok);
    ASSERT_EQ("user subscriber@mail.ru already follows on subscripton@mail.ru", reason);

    // 7.Stop server
    api_grpc::stopServer();
    serverThread.join();
}

TEST(ServerSuite, Estimate) {
    // 1.Run server
    std::shared_ptr<MockStorageManager> pDBManager = std::make_shared<MockStorageManager>();
    std::thread                         serverThread(api_grpc::runServer, SERVER_IP, pDBManager);

    // 2.Create client
    std::shared_ptr<grpc::Channel> pChannel =
        grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials());

    test_grpc_api::TestClient client(pChannel);

    // 3.Add user
    client.registrateUser("someUser@mail.ru", "someUserName", "someUserSername", std::nullopt);

    // 4.Estimate establishment: invalid case
    const std::map<std::string, unsigned> dishes = {
        {"hinkali", 5}, {"harcho", 4}, {"hachapuri", 5}};
    auto [ok, reason] =
        client.estimateEstablishment("NON_EXISTEN_USER@mail.ru", "ProHinkali", "Moscow", dishes);
    ASSERT_EQ(false, ok);
    ASSERT_EQ("user is not registrated: NON_EXISTEN_USER@mail.ru", reason);

    // 5.Estimate establishment: valid case
    std::tie(ok, reason) =
        client.estimateEstablishment("someUser@mail.ru", "ProHinkali", "Moscow", dishes);

    // 6.Stop server
    api_grpc::stopServer();
    serverThread.join();
}

TEST(ServerSuite, GetEstimations) {
    // 1.Run server
    std::shared_ptr<MockStorageManager> pDBManager = std::make_shared<MockStorageManager>();
    std::thread                         serverThread(api_grpc::runServer, SERVER_IP, pDBManager);

    // 2.Create client
    std::shared_ptr<grpc::Channel> pChannel =
        grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials());

    test_grpc_api::TestClient client(pChannel);

    // 3.Get establishments: invalid case
    std::vector<TestClient::Establishment_t> establishments;
    auto [ok, reason] = client.getEstimations("non-existen-user@mail.ru", establishments);
    ASSERT_EQ(false, ok);
    ASSERT_EQ("user is not registrated: non-existen-user@mail.ru", reason);

    // 4.Add user and his establishments (valid case)
    client.registrateUser("someUser@mail.ru", "someUserName", "someUserSername", std::nullopt);

    const std::map<std::string, unsigned> dishes1 = {
        {"hinkali", 5}, {"harcho", 4}, {"hachapuri", 5}};
    client.estimateEstablishment("someUser@mail.ru", "ProHinkali", "Moscow", dishes1);

    const std::map<std::string, unsigned> dishes2 = {{"borsch", 3}, {"pelmeni", 5}};
    client.estimateEstablishment("someUser@mail.ru", "TarasBulba", "Moscow", dishes1);

    // 5.Get establishments: valid case
    std::tie(ok, reason) = client.getEstimations("someUser@mail.ru", establishments);
    ASSERT_EQ(true, ok);

    const auto& [est1Name, est1Address, estDishes1] = establishments[0];
    ASSERT_EQ("ProHinkali", est1Name);
    ASSERT_EQ("Moscow", est1Address);

    const auto& [est2Name, est2Address, estDishes2] = establishments[1];
    ASSERT_EQ("TarasBulba", est2Name);
    ASSERT_EQ("Moscow", est2Address);

    // 6.Stop server
    api_grpc::stopServer();
    serverThread.join();
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}