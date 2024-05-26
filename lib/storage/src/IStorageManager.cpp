#include <storage/IStorageManager.h>

#include "json-manager/JsonStorageManager.h"
#include "postgres-manager/PostgresStorageManager.h"
#include "sqlite-manager/SqliteStorageManager.h"

using storage::IStorageManager;
using storage::StorageManagerType;
using storage::JsonStorageManager;
using storage::PostgresStorageManager;
using storage::SqliteStorageManager;

//! Function for create storage manager implementation
std::shared_ptr<IStorageManager> IStorageManager::create(
    const StorageManagerType type,
    const std::string& storePath
)
{
    switch (type) {
    case StorageManagerType::JSON:
        return std::make_shared<JsonStorageManager>(storePath);
    case StorageManagerType::POSTGRES:
        return std::make_shared<PostgresStorageManager>(storePath);
    case StorageManagerType::SQLITE:
        return std::make_shared<SqliteStorageManager>(storePath);
    default:
        throw "unspecified storage type";
    }
}
