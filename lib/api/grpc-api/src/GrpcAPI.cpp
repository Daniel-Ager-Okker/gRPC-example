#include <grpc-api/GrpcAPI.h>

#include "ServerGRPC.h"

#include <grpcpp/server.h>
#include <grpcpp/server_builder.h>

using api_grpc::ServerGRPC;

using grpc::Server;
using grpc::ServerBuilder;

void api_grpc::runServer(const std::string& address, std::shared_ptr<storage::IStorageManager>& pStoreManager) {
    ServerGRPC serverGRPC(pStoreManager);

    ServerBuilder serverBuilder;
    serverBuilder.AddListeningPort(address, grpc::InsecureServerCredentials());
    serverBuilder.RegisterService(&serverGRPC);
    std::unique_ptr<Server> server(serverBuilder.BuildAndStart());
    std::cout << "Server listening on " << address << std::endl;
    server->Wait();
}