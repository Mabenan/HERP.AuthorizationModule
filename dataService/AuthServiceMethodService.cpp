#include <QxOrm_Impl.h>
#include <AuthServiceMethodService.h>

#include <memory>

HERP_REGISTER_CPP_HERP_AUTHORIZATION_MODULE(AuthServiceMethodInput)
HERP_REGISTER_CPP_HERP_AUTHORIZATION_MODULE(AuthServiceMethodOutput)
HERP_REGISTER_CPP_HERP_AUTHORIZATION_MODULE(AuthServiceMethodService)

QX_SERVICE_IX_PARAMETER_SERIALIZATION_CPP(AuthServiceMethodInput)
QX_SERVICE_IX_PARAMETER_SERIALIZATION_CPP(AuthServiceMethodOutput)


REGISTER_AUTH(AuthServiceMethod,list_auth_service_method_ptr)
REGISTER_OUTPUT_PARAMETER_BASE(auth_service_method_ptr, list_auth_service_method_ptr)
REGISTER_AUTH_SERVICE_BASE(AuthServiceMethodInput, AuthServiceMethodOutput, AuthServiceMethod, list_auth_service_method)
REGISTER_SERVICE_BASE(AuthServiceMethodService)
namespace qx {

template <> void register_class(QxClass<AuthServiceMethodInput> &t) {
}

template <> void register_class(QxClass<AuthServiceMethodOutput> &t) {
}

} // namespace qx
