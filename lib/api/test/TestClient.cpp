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

//! Method for estimate establishment
std::pair<bool, std::string>
test_grpc_api::TestClient::estimateEstablishment(const std::string& userMail,
                                                 const std::string& establishmentName,
                                                 const std::string& establishmentAddress,
                                                 const std::map<std::string, unsigned>& dishes) {

    ClientContext context;

    // 1.Prepare request
    EstimationReq req;
    req.set_e_mail(userMail);

    EstablishmentData* pData = new EstablishmentData();
    pData->set_name(establishmentName);
    pData->set_address(establishmentAddress);

    auto pDataDishes = pData->mutable_dishes();
    for (const auto& [dishName, estimation] : dishes) {
        (*pDataDishes)[dishName] = estimation;
    }

    req.set_allocated_establishment(pData);

    // 2.Call rpc-method and handle server response
    EstimatonResp resp;
    pStub_->EstimateEstablishment(&context, req, &resp);

    const bool        ok     = resp.ok();
    const std::string reason = resp.has_reason() ? resp.reason() : "";

    return std::make_pair(ok, reason);
}

//! Method for get subscription establishments
std::pair<bool, std::string> test_grpc_api::TestClient::getEstimations(
    const std::string&                                       subscribtionMail,
    std::vector<test_grpc_api::TestClient::Establishment_t>& establishments) {

    ClientContext context;

    // 1.Prepare request
    SubscriptionEstimationsReq req;
    req.set_subscribtion_mail(subscribtionMail);

    // 2.Call rpc-method and handle server response
    SubscriptionEstimationsResp resp;
    pStub_->GetSubscriptionEstimations(&context, req, &resp);

    const auto& respEstablishments = resp.estimations();
    for (const auto& est : respEstablishments) {
        // fill dishes
        std::map<std::string, unsigned> dishes;

        const auto& respDishes = est.dishes();
        for (const auto& [dishName, estimation] : respDishes) {
            dishes[dishName] = estimation;
        }

        Establishment_t establishment = {est.name(), est.address(), dishes};
        establishments.push_back(establishment);
    }

    const bool        ok     = resp.ok();
    const std::string reason = resp.has_reason() ? resp.reason() : "";

    return std::make_pair(ok, reason);
}