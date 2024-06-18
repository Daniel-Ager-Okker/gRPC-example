#include "TestClient.h"

using grpc::Channel;
using grpc::ClientContext;

test_grpc_api::TestClient::TestClient(std::shared_ptr<Channel> channel) :
    pStub_(GrpcTransport::NewStub(channel)) {}

//! Method for new user registration
std::pair<bool, std::string>
test_grpc_api::TestClient::registrateUser(const std::string&         electronic_mail,
                                          const std::string&         name,
                                          const std::string&         sername,
                                          std::optional<std::string> phone_number) {
    ClientContext context;

    // 1.Prepare request
    ClientRegistrationReq req;
    req.set_electronic_mail(electronic_mail);
    req.set_name(name);
    req.set_sername(sername);
    if (phone_number.has_value()) req.set_phone_number(phone_number.value());

    // 2.Call rpc-method and handle server response
    ClientRegistrationResp resp;
    pStub_->Registrate(&context, req, &resp);

    const bool        ok     = resp.ok();
    const std::string reason = resp.has_reason() ? resp.reason() : "";

    return std::make_pair(ok, reason);
}

//! Method for subscrive on user
std::pair<bool, std::string> test_grpc_api::TestClient::subscribe(const std::string& subscriber,
                                                                  const std::string& subscribtion) {
    ClientContext context;

    // 1.Prepare request
    SubscriptionReq req;
    req.set_subscriber_e_mail(subscriber);
    req.set_subscription_e_mail(subscribtion);

    // 2.Call rpc-method and handle server response
    SubscriptionResp resp;
    pStub_->Subscribe(&context, req, &resp);

    const bool        ok     = resp.ok();
    const std::string reason = resp.has_reason() ? resp.reason() : "";

    return std::make_pair(ok, reason);
}