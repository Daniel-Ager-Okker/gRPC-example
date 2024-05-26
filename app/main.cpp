#include <grpc-api/GrpcAPI.h>
#include <storage/IStorageManager.h>

using storage::IStorageManager;
using storage::StorageManagerType;

int main() {
    // 1.Create json-database manager
    std::shared_ptr<IStorageManager> pDBManager = IStorageManager::create(StorageManagerType::JSON, "database.json");

    // 2.Run server
    api_grpc::runServer(":4509", pDBManager);

    return 0;
}