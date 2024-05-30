#include "main.grpc.pb.h"

#include <memory>

namespace storage
{

class IStorageManager;

}

namespace api_grpc
{

//! gRPC-server implementation
class ServerGRPC final : public GrpcTransport::Service {
public:
    //! Ctor by default
    ServerGRPC() = delete;

    //! Constructor
    ServerGRPC(std::shared_ptr<storage::IStorageManager> pStoreManager);

    //! Destructor
    ~ServerGRPC();

    //! Registrate new user
    grpc::Status Registrate(
        grpc::ServerContext* context,
        const ClientRegistrationReq* request,
        ClientRegistrationResp* response
    ) override;

    //! Subscribe to user
    grpc::Status Subscribe(
        grpc::ServerContext* context,
        const SubscriptionReq* request,
        SubscriptionResp* response
    ) override;
    
    //! Estimate dishes
    grpc::Status EstimateEstablishment(
        grpc::ServerContext* context,
        const EstimationReq* request,
        EstimatonResp* response
    ) override;
    
    //! Subscription estimations
    grpc::Status GetSubscriptionEstimations(
        grpc::ServerContext* context,
        const SubscriptionEstimationsReq* request,
        SubscriptionEstimationsResp* response
    ) override;

private:
    std::shared_ptr<storage::IStorageManager> pStorageManager_;
};

}