#pragma once

#include <memory>
#include <string>

namespace storage
{

class IStorageManager;

}

namespace api_grpc
{

//! Public function for start gRPC-server
void runServer(const std::string& address, std::shared_ptr<storage::IStorageManager> pStoreManager);

//! Public function for stop gRPC-server
void stopServer();

} // namespace api_grpc