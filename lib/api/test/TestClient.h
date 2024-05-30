#pragma once

#include <memory>

#include <grpcpp/channel.h>

// need to include private headers
#include "../src/main.grpc.pb.h"

namespace test_grpc_api
{

class TestClient {
public:
    TestClient(std::shared_ptr<grpc::Channel> pChannel);

    //! Method for new user registration
    std::pair<bool, std::string> registrateUser(
        const std::string& electronic_mail,
        const std::string& name,
        const std::string& sername,
        std::optional<std::string> phone_number
    );

private:
    std::unique_ptr<GrpcTransport::Stub> pStub_;
};

}