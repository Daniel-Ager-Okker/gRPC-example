#include "SqliteStorageManager.h"

using namespace storage;

//! Ctor with path
SqliteStorageManager::SqliteStorageManager(const std::string& path) : path_(path) {}

//! Destructor
SqliteStorageManager::~SqliteStorageManager() {}

//! Check if has user in storage
bool SqliteStorageManager::hasUser(const std::string& /*eMail*/) {
    // TODO
    return true;
}

//! Put new user into the database
void SqliteStorageManager::putUser(const UserDTO& /*userInfo*/) {
    // TODO
}

//! Remove user from database
void SqliteStorageManager::popUser(const UserDTO& /*useInfo*/) {
    // TODO
}

//! Make record about user subscription
bool SqliteStorageManager::subscribeUserOnAnother(
    const std::string& /*subscriber*/,
    const std::string& /*subscription*/
)
{
    // TODO
    return false;
}

//! Make record about user going to some place
bool SqliteStorageManager::addUserEstablishment(
    const std::string& /*eMail*/,
    const EstablishmentDTO& /*placeInfo*/
)
{
    // TODO
    return false;
}

//! Get user establishments info from db
std::vector<EstablishmentDTO> SqliteStorageManager::getUserEstablishments(
    const std::string& eMail
)
{
    // TODO
    return std::vector<EstablishmentDTO>{};
}