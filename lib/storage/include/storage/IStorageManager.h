#pragma once

#include <memory>
#include <string>
#include <vector>

namespace storage
{

class EstablishmentDTO;
class UserDTO;

//! Storage implementation types
enum class StorageManagerType {
    JSON     = 0,
    SQLITE   = 1,
    POSTGRES = 2
};

//! Main interface to interact with storage
class IStorageManager {
public:
    //! Constuctor
    IStorageManager() = default;

    //! Destructor
    virtual ~IStorageManager() = default;

    //! Function for create storage manager implementation
    static std::shared_ptr<IStorageManager> create(const StorageManagerType type, const std::string& storePath);

    //! Check if has user in storage
    virtual bool hasUser(const std::string& eMail) = 0;

    //! Put new user into the database
    virtual void putUser(const UserDTO& userInfo) = 0;

    //! Remove user from database
    virtual void popUser(const UserDTO& userInfo) = 0;

    //! Make record about user subscription
    virtual bool subscribeUserOnAnother(
        const std::string& subscriber,
        const std::string& subscription
    ) = 0;

    //! Make record about user going to some place
    virtual bool addUserEstablishment(
        const std::string& eMail,
        const EstablishmentDTO& placeInfo
    ) = 0;

    //! Get user establishments info frpm db
    virtual std::vector<EstablishmentDTO> getUserEstablishments(
        const std::string& eMail
    ) = 0;
};

}