#include "PostgresStorageManager.h"

using namespace storage;

//! Ctor by path
PostgresStorageManager::PostgresStorageManager(const std::string& address) : address_(address) {}

//! Destructor
PostgresStorageManager::~PostgresStorageManager() {}

//! Check if has user in storage
bool PostgresStorageManager::hasUser(const std::string& /*eMail*/) {
    // TODO
    return true;
}

//! Put new user into the database
void PostgresStorageManager::putUser(const UserDTO& /*userInfo*/) {
    // TODO
}

//! Remove user from database
void PostgresStorageManager::popUser(const UserDTO& /*useInfo*/) {
    // TODO
}

//! Make record about user subscription
bool PostgresStorageManager::subscribeUserOnAnother(
    const std::string& /*subscriber*/,
    const std::string& /*subscription*/
)
{
    // TODO
    return false;
}

//! Make record about user going to some place
bool PostgresStorageManager::addUserEstablishment(
    const std::string& /*eMail*/,
    const EstablishmentDTO& /*placeInfo*/
)
{
    // TODO
    return false;
}

//! Get user establishments info from db
std::vector<EstablishmentDTO> PostgresStorageManager::getUserEstablishments(
    const std::string& eMail
)
{
    // TODO
    return std::vector<EstablishmentDTO>{};
}