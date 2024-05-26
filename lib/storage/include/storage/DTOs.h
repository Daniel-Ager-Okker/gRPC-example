#pragma once

#include <map>
#include <string>
#include <optional>

namespace storage
{

//! Data transfer object with info about user
struct UserDTO {
    std::string eMail;
    std::string name;
    std::string sername;
    std::string phoneNumber;
};

//! Data transfer object for establishment going
struct EstablishmentDTO {
    std::string                     name;
    std::string                     address;
    std::map<std::string, unsigned> dishes;
};

}