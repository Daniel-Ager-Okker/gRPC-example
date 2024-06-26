// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: main.proto

#include "main.pb.h"
#include "main.grpc.pb.h"

#include <functional>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/impl/channel_interface.h>
#include <grpcpp/impl/client_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/rpc_service_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/sync_stream.h>

static const char* GrpcTransport_method_names[] = {
  "/GrpcTransport/Registrate",
  "/GrpcTransport/Subscribe",
  "/GrpcTransport/EstimateEstablishment",
  "/GrpcTransport/GetSubscriptionEstimations",
};

std::unique_ptr< GrpcTransport::Stub> GrpcTransport::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< GrpcTransport::Stub> stub(new GrpcTransport::Stub(channel, options));
  return stub;
}

GrpcTransport::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_Registrate_(GrpcTransport_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_Subscribe_(GrpcTransport_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_EstimateEstablishment_(GrpcTransport_method_names[2], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_GetSubscriptionEstimations_(GrpcTransport_method_names[3], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status GrpcTransport::Stub::Registrate(::grpc::ClientContext* context, const ::ClientRegistrationReq& request, ::ClientRegistrationResp* response) {
  return ::grpc::internal::BlockingUnaryCall< ::ClientRegistrationReq, ::ClientRegistrationResp, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_Registrate_, context, request, response);
}

void GrpcTransport::Stub::async::Registrate(::grpc::ClientContext* context, const ::ClientRegistrationReq* request, ::ClientRegistrationResp* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::ClientRegistrationReq, ::ClientRegistrationResp, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Registrate_, context, request, response, std::move(f));
}

void GrpcTransport::Stub::async::Registrate(::grpc::ClientContext* context, const ::ClientRegistrationReq* request, ::ClientRegistrationResp* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Registrate_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::ClientRegistrationResp>* GrpcTransport::Stub::PrepareAsyncRegistrateRaw(::grpc::ClientContext* context, const ::ClientRegistrationReq& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::ClientRegistrationResp, ::ClientRegistrationReq, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_Registrate_, context, request);
}

::grpc::ClientAsyncResponseReader< ::ClientRegistrationResp>* GrpcTransport::Stub::AsyncRegistrateRaw(::grpc::ClientContext* context, const ::ClientRegistrationReq& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncRegistrateRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status GrpcTransport::Stub::Subscribe(::grpc::ClientContext* context, const ::SubscriptionReq& request, ::SubscriptionResp* response) {
  return ::grpc::internal::BlockingUnaryCall< ::SubscriptionReq, ::SubscriptionResp, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_Subscribe_, context, request, response);
}

void GrpcTransport::Stub::async::Subscribe(::grpc::ClientContext* context, const ::SubscriptionReq* request, ::SubscriptionResp* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::SubscriptionReq, ::SubscriptionResp, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Subscribe_, context, request, response, std::move(f));
}

void GrpcTransport::Stub::async::Subscribe(::grpc::ClientContext* context, const ::SubscriptionReq* request, ::SubscriptionResp* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Subscribe_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::SubscriptionResp>* GrpcTransport::Stub::PrepareAsyncSubscribeRaw(::grpc::ClientContext* context, const ::SubscriptionReq& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::SubscriptionResp, ::SubscriptionReq, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_Subscribe_, context, request);
}

::grpc::ClientAsyncResponseReader< ::SubscriptionResp>* GrpcTransport::Stub::AsyncSubscribeRaw(::grpc::ClientContext* context, const ::SubscriptionReq& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncSubscribeRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status GrpcTransport::Stub::EstimateEstablishment(::grpc::ClientContext* context, const ::EstimationReq& request, ::EstimatonResp* response) {
  return ::grpc::internal::BlockingUnaryCall< ::EstimationReq, ::EstimatonResp, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_EstimateEstablishment_, context, request, response);
}

void GrpcTransport::Stub::async::EstimateEstablishment(::grpc::ClientContext* context, const ::EstimationReq* request, ::EstimatonResp* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::EstimationReq, ::EstimatonResp, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_EstimateEstablishment_, context, request, response, std::move(f));
}

void GrpcTransport::Stub::async::EstimateEstablishment(::grpc::ClientContext* context, const ::EstimationReq* request, ::EstimatonResp* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_EstimateEstablishment_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::EstimatonResp>* GrpcTransport::Stub::PrepareAsyncEstimateEstablishmentRaw(::grpc::ClientContext* context, const ::EstimationReq& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::EstimatonResp, ::EstimationReq, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_EstimateEstablishment_, context, request);
}

::grpc::ClientAsyncResponseReader< ::EstimatonResp>* GrpcTransport::Stub::AsyncEstimateEstablishmentRaw(::grpc::ClientContext* context, const ::EstimationReq& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncEstimateEstablishmentRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status GrpcTransport::Stub::GetSubscriptionEstimations(::grpc::ClientContext* context, const ::SubscriptionEstimationsReq& request, ::SubscriptionEstimationsResp* response) {
  return ::grpc::internal::BlockingUnaryCall< ::SubscriptionEstimationsReq, ::SubscriptionEstimationsResp, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_GetSubscriptionEstimations_, context, request, response);
}

void GrpcTransport::Stub::async::GetSubscriptionEstimations(::grpc::ClientContext* context, const ::SubscriptionEstimationsReq* request, ::SubscriptionEstimationsResp* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::SubscriptionEstimationsReq, ::SubscriptionEstimationsResp, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetSubscriptionEstimations_, context, request, response, std::move(f));
}

void GrpcTransport::Stub::async::GetSubscriptionEstimations(::grpc::ClientContext* context, const ::SubscriptionEstimationsReq* request, ::SubscriptionEstimationsResp* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetSubscriptionEstimations_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::SubscriptionEstimationsResp>* GrpcTransport::Stub::PrepareAsyncGetSubscriptionEstimationsRaw(::grpc::ClientContext* context, const ::SubscriptionEstimationsReq& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::SubscriptionEstimationsResp, ::SubscriptionEstimationsReq, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_GetSubscriptionEstimations_, context, request);
}

::grpc::ClientAsyncResponseReader< ::SubscriptionEstimationsResp>* GrpcTransport::Stub::AsyncGetSubscriptionEstimationsRaw(::grpc::ClientContext* context, const ::SubscriptionEstimationsReq& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncGetSubscriptionEstimationsRaw(context, request, cq);
  result->StartCall();
  return result;
}

GrpcTransport::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      GrpcTransport_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< GrpcTransport::Service, ::ClientRegistrationReq, ::ClientRegistrationResp, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](GrpcTransport::Service* service,
             ::grpc::ServerContext* ctx,
             const ::ClientRegistrationReq* req,
             ::ClientRegistrationResp* resp) {
               return service->Registrate(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      GrpcTransport_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< GrpcTransport::Service, ::SubscriptionReq, ::SubscriptionResp, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](GrpcTransport::Service* service,
             ::grpc::ServerContext* ctx,
             const ::SubscriptionReq* req,
             ::SubscriptionResp* resp) {
               return service->Subscribe(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      GrpcTransport_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< GrpcTransport::Service, ::EstimationReq, ::EstimatonResp, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](GrpcTransport::Service* service,
             ::grpc::ServerContext* ctx,
             const ::EstimationReq* req,
             ::EstimatonResp* resp) {
               return service->EstimateEstablishment(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      GrpcTransport_method_names[3],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< GrpcTransport::Service, ::SubscriptionEstimationsReq, ::SubscriptionEstimationsResp, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](GrpcTransport::Service* service,
             ::grpc::ServerContext* ctx,
             const ::SubscriptionEstimationsReq* req,
             ::SubscriptionEstimationsResp* resp) {
               return service->GetSubscriptionEstimations(ctx, req, resp);
             }, this)));
}

GrpcTransport::Service::~Service() {
}

::grpc::Status GrpcTransport::Service::Registrate(::grpc::ServerContext* context, const ::ClientRegistrationReq* request, ::ClientRegistrationResp* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status GrpcTransport::Service::Subscribe(::grpc::ServerContext* context, const ::SubscriptionReq* request, ::SubscriptionResp* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status GrpcTransport::Service::EstimateEstablishment(::grpc::ServerContext* context, const ::EstimationReq* request, ::EstimatonResp* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status GrpcTransport::Service::GetSubscriptionEstimations(::grpc::ServerContext* context, const ::SubscriptionEstimationsReq* request, ::SubscriptionEstimationsResp* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


