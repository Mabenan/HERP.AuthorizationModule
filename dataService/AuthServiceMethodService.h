#ifndef AUTHSERVICEMETHODSERVICE_H
#define AUTHSERVICEMETHODSERVICE_H

#include <HERP.AuthorizationModule.Precompiled.h>
#include <data/AuthServiceMethod.h>
#include <dataService/authparameter.h>
#include <dataService/authservicebase.h>

class HERP_AUTHORIZATION_MODULE_DLL_EXPORT AuthServiceMethodInput
    : public AuthParameter<AuthServiceMethod, list_auth_service_method_ptr> {
  QX_SERVICE_IX_PARAMETER_SERIALIZATION_HPP(AuthServiceMethodInput);
};
using AuthServiceMethodInputBase = AuthParameter<AuthServiceMethod, list_auth_service_method_ptr>;
HERP_REGISTER_HPP_HERP_AUTHORIZATION_MODULE(AuthServiceMethodInput, AuthServiceMethodInputBase, 0)
using auth_service_method_service_input_ptr = std::shared_ptr<AuthServiceMethodInput>;

class HERP_AUTHORIZATION_MODULE_DLL_EXPORT AuthServiceMethodOutput
    : public QxOutputParamaterBase<auth_service_method_ptr, list_auth_service_method_ptr> {
  QX_SERVICE_IX_PARAMETER_SERIALIZATION_HPP(AuthServiceMethodOutput);
};
using AuthServiceMethodOutputBase =
    QxOutputParamaterBase<auth_service_method_ptr, list_auth_service_method_ptr>;
HERP_REGISTER_HPP_HERP_AUTHORIZATION_MODULE(AuthServiceMethodOutput, AuthServiceMethodOutputBase,
                                            0)
using auth_service_method_service_output_ptr = std::shared_ptr<AuthServiceMethodOutput>;

typedef AuthServiceBase<AuthServiceMethodInput, AuthServiceMethodOutput, AuthServiceMethod, list_auth_service_method>
    auth_service_method_service_base_class;
class HERP_AUTHORIZATION_MODULE_DLL_EXPORT AuthServiceMethodService
    : public auth_service_method_service_base_class {

  QX_REGISTER_FRIEND_CLASS(AuthServiceMethodService)

public:
  AuthServiceMethodService()
      : auth_service_method_service_base_class(QStringLiteral("AuthServiceMethodService")) {
    ;
  }
  ~AuthServiceMethodService() override { ; }
};

HERP_REGISTER_HPP_HERP_AUTHORIZATION_MODULE(AuthServiceMethodService,
                                            auth_service_method_service_base_class, 0)
using auth_service_method_service_ptr = std::shared_ptr<AuthServiceMethodService>;
#endif // AUTHSERVICEMETHODSERVICE_H
