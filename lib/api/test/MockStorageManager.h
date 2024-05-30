// include for mock
#include "../../storage/include/storage/IStorageManager.h"
#include "../../storage/include/storage/DTOs.h"

#include <gmock/gmock.h>

#include <map>

namespace test_grpc_api
{

class MockStorageManager : public storage::IStorageManager {
public:
    bool hasUser(const std::string& eMail) override;

    void putUser(const storage::UserDTO& userInfo) override;

    void popUser(const storage::UserDTO& userInfo) override;

    bool subscribeUserOnAnother(
        const std::string& subscriber,
        const std::string& subscription
    ) override;

    bool addUserEstablishment(
        const std::string& eMail,
        const storage::EstablishmentDTO& placeInfo
    ) override;

    std::vector<storage::EstablishmentDTO> getUserEstablishments(
        const std::string& eMail
    ) override;

private:
    struct UserData {
        std::set<std::string>                  subscribers;
        std::set<std::string>                  subscribtions;
        storage::UserDTO                       userInfo;
        std::vector<storage::EstablishmentDTO> establishments_;
    };
    std::map<std::string, UserData> users_;
};

}