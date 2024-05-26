#include "../../include/storage/IStorageManager.h"
#include "../../include/storage/DTOs.h"

#include <string>

namespace storage
{

//! PostgreSQL implementation for storage manager interface
class PostgresStorageManager final : public IStorageManager {
public:
    //! Ctor by default
    PostgresStorageManager() = delete;

    //! Ctor by path
    PostgresStorageManager(const std::string& address);

    //! Destructor
    ~PostgresStorageManager();

    //! Check if has user in storage
    bool hasUser(const std::string& eMail) override;

    //! Put new user into the database
    void putUser(const UserDTO& userInfo) override;

    //! Remove user from database
    void popUser(const UserDTO& useInfo) override;

    //! Make record about user subscription
    bool subscribeUserOnAnother(
        const std::string& subscriber,
        const std::string& subscription
    ) override;

    //! Make record about user going to some place
    bool addUserEstablishment(
        const std::string& eMail,
        const EstablishmentDTO& placeInfo
    ) override;

    //! Get user establishments info frpm db
    std::vector<EstablishmentDTO> getUserEstablishments(
        const std::string& eMail
    ) override;

private:
    //! IP-address of database
    const std::string address_;
};

}