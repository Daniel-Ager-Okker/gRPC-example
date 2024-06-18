#include <api/GrpcAPI.h>

#include "ServerGRPC.h"

#include <grpcpp/server.h>
#include <grpcpp/server_builder.h>

using api_grpc::ServerGRPC;

using grpc::Server;
using grpc::ServerBuilder;

ServerGRPC*             pService = nullptr;
std::unique_ptr<Server> pServer  = nullptr;

void api_grpc::runServer(const std::string&                        address,
                         std::shared_ptr<storage::IStorageManager> pStoreManager) {
    pService = new ServerGRPC(pStoreManager);

    ServerBuilder serverBuilder;
    serverBuilder.AddListeningPort(address, grpc::InsecureServerCredentials());
    serverBuilder.RegisterService(pService);
    pServer = serverBuilder.BuildAndStart();
    std::cout << "Server listening on " << address << std::endl;
    pServer->Wait();
}

//! Public function for stop gRPC-server
void api_grpc::stopServer() {
    pServer->Shutdown();

    delete pService;
    pServer.release();
}