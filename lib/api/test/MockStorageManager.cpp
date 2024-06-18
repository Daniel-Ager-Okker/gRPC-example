#include "MockStorageManager.h"

bool test_grpc_api::MockStorageManager::hasUser(const std::string& eMail) {
    return users_.find(eMail) != users_.end();
}

void test_grpc_api::MockStorageManager::putUser(const storage::UserDTO& userInfo) {
    users_[userInfo.eMail] = UserData{.subscribers    = std::set<std::string>(),
                                      .subscribtions  = std::set<std::string>(),
                                      .userInfo       = userInfo,
                                      .establishments = std::vector<storage::EstablishmentDTO>()};
}

void test_grpc_api::MockStorageManager::popUser(const storage::UserDTO& userInfo) {
    users_.erase(userInfo.eMail);
}

bool test_grpc_api::MockStorageManager::subscribeUserOnAnother(const std::string& subscriber,
                                                               const std::string& subscription) {
    // 1.Check if have such subscriber among users
    auto subscriberIt = users_.find(subscriber);
    if (subscriberIt == users_.end()) return false;

    // 2.Check if have such subscription among users
    auto subscriptionIt = users_.find(subscription);
    if (subscriptionIt == users_.end()) return false;

    // 3.Add information
    subscriberIt->second.subscribtions.insert(subscription);
    subscriptionIt->second.subscribers.insert(subscriber);

    return true;
}

bool test_grpc_api::MockStorageManager::addUserEstablishment(
    const std::string&               eMail,
    const storage::EstablishmentDTO& placeInfo) {
    // 1.Check if have such subscriber among users
    auto it = users_.find(eMail);
    if (it == users_.end()) return false;

    // 2.Add information
    it->second.establishments.push_back(placeInfo);
    return true;
}

std::vector<storage::EstablishmentDTO>
test_grpc_api::MockStorageManager::getUserEstablishments(const std::string& eMail) {

    // 1.Check if have such subscriber among users
    auto it = users_.find(eMail);
    if (it == users_.end()) return std::vector<storage::EstablishmentDTO>();

    return it->second.establishments;
}
