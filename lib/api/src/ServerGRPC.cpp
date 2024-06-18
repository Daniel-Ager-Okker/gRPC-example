#include "ServerGRPC.h"

#include <storage/DTOs.h>
#include <storage/IStorageManager.h>

using grpc::ServerContext;
using grpc::Status;

using api_grpc::ServerGRPC;

using storage::EstablishmentDTO;
using storage::IStorageManager;
using storage::UserDTO;

namespace
{

EstablishmentDTO getEstablishmentByReq(const EstimationReq* pRequest) {
    const EstablishmentData establishment = pRequest->establishment();

    EstablishmentDTO dto;
    dto.name    = establishment.name();
    dto.address = establishment.address();
    for (const auto& item : establishment.dishes()) {
        dto.dishes[item.first] = item.second;
    }
    return dto;
}

void fillEstablishmentByDTO(EstablishmentData* pData, const EstablishmentDTO& dto) {
    pData->set_name(dto.name);
    pData->set_address(dto.address);

    auto pDataDishes = pData->mutable_dishes();
    for (const auto& [dishName, score] : dto.dishes) {
        (*pDataDishes)[dishName] = score;
    }
}

} // namespace

//! Constructor
ServerGRPC::ServerGRPC(std::shared_ptr<IStorageManager> pStoreManager) :
    pStorageManager_(pStoreManager) {}

//! Destructor
ServerGRPC::~ServerGRPC() {}

//! Registrate new user
Status ServerGRPC::Registrate(ServerContext*               context,
                              const ClientRegistrationReq* pRequest,
                              ClientRegistrationResp*      pResponse) {

    // 1.Check if we have such e-mail in db already
    if (pStorageManager_->hasUser(pRequest->electronic_mail())) {
        pResponse->set_ok(false);
        pResponse->set_reason("already have such e-mail");
        return Status::OK;
    }

    // 2.Put new user into the database
    const UserDTO userInfo{.eMail   = pRequest->electronic_mail(),
                           .name    = pRequest->name(),
                           .sername = pRequest->sername(),
                           .phoneNumber =
                               pRequest->has_phone_number() ? pRequest->phone_number() : ""};
    pStorageManager_->putUser(userInfo);
    pResponse->set_ok(true);

    return Status::OK;
}

//! Subscribe to user
Status ServerGRPC::Subscribe(ServerContext*         context,
                             const SubscriptionReq* request,
                             SubscriptionResp*      response) {
    response->set_ok(false);

    // 1.Validation: has subscriber user
    const std::string& subscriber = request->subscriber_e_mail();
    if (!pStorageManager_->hasUser(subscriber)) {
        response->set_reason("user is not registrated: " + subscriber);
        return Status::OK;
    }

    // 2.Validation: has subscribtion user
    const std::string& subscribtion = request->subscription_e_mail();
    if (!pStorageManager_->hasUser(subscribtion)) {
        response->set_reason("user is not registrated: " + subscribtion);
        return Status::OK;
    }

    // 3.Make corresponding record in db
    const bool subscribed = pStorageManager_->subscribeUserOnAnother(subscriber, subscribtion);
    if (!subscribed) {
        const std::string msg = "user " + subscriber + " already follows on " + subscribtion;
        response->set_reason(msg);
        return Status::OK;
    }
    response->set_ok(true);
    return Status::OK;
}

//! Estimate dishes
Status ServerGRPC::EstimateEstablishment(ServerContext*       context,
                                         const EstimationReq* request,
                                         EstimatonResp*       response) {
    response->set_ok(false);

    // 1.Validation: has client-user
    const std::string& userMail = request->e_mail();
    if (!pStorageManager_->hasUser(userMail)) {
        response->set_reason("user is not registrated: " + userMail);
        return Status::OK;
    }

    // 2.Add corresponding record to db
    const EstablishmentDTO establishmentInfo = getEstablishmentByReq(request);
    if (!pStorageManager_->addUserEstablishment(userMail, establishmentInfo)) {
        response->set_reason("problem while adding info about establishment");
        return Status::OK;
    }
    response->set_ok(true);
    return Status::OK;
}

//! Subscription estimations
Status ServerGRPC::GetSubscriptionEstimations(ServerContext*                    context,
                                              const SubscriptionEstimationsReq* request,
                                              SubscriptionEstimationsResp*      response) {
    // 1.Validation: has subscribtion user
    const std::string& eMail = request->subscribtion_mail();
    if (!pStorageManager_->hasUser(eMail)) {
        response->set_ok(false);
        response->set_reason("user is not registrated: " + eMail);
        return Status::OK;
    }

    // 3.Get subscription from database
    const std::vector<EstablishmentDTO> places = pStorageManager_->getUserEstablishments(eMail);
    for (const EstablishmentDTO& dto : places) {
        EstablishmentData* pData = response->add_estimations();
        fillEstablishmentByDTO(pData, dto);
    }
    response->set_ok(true);
    return Status::OK;
}