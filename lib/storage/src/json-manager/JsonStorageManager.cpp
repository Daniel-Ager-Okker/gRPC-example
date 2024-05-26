#include "JsonStorageManager.h"

using namespace storage;

//! Ctor with path
JsonStorageManager::JsonStorageManager(const std::string& path) : path_(path) {}

//! Destructor
JsonStorageManager::~JsonStorageManager() {}

//! Check if has user in storage
bool JsonStorageManager::hasUser(const std::string& /*eMail*/) {
    // TODO
    return true;
}

//! Put new user into the database
void JsonStorageManager::putUser(const UserDTO& /*userInfo*/) {
    // TODO
}

//! Remove user from database
void JsonStorageManager::popUser(const UserDTO& /*useInfo*/) {
    // TODO
}

//! Make record about user subscription
bool JsonStorageManager::subscribeUserOnAnother(
    const std::string& /*subscriber*/,
    const std::string& /*subscription*/
)
{
    // TODO
    return false;
}

//! Make record about user going to some place
bool JsonStorageManager::addUserEstablishment(
    const std::string& /*eMail*/,
    const EstablishmentDTO& /*placeInfo*/
)
{
    // TODO
    return false;
}

//! Get user establishments info frpm db
std::vector<EstablishmentDTO> JsonStorageManager::getUserEstablishments(
    const std::string& eMail
)
{
    // TODO
    return std::vector<EstablishmentDTO>{};
}