/*
 * AuthUser.h
 *
 *  Created on: 25.02.2020
 *      Author: daniel
 */

#ifndef REPS_HERP_AUTHORIZATIONMODULE_DATASERVICE_AUTHUSERSERVICE_H_
#define REPS_HERP_AUTHORIZATIONMODULE_DATASERVICE_AUTHUSERSERVICE_H_

#include "authparameter.h"
#include "authservicebase.h"
#include <HERP.AuthorizationModule.Precompiled.h>
#include <QString>
#include <QxService/IxParameter.h>
#include <QxService/QxService.h>
#include <QxServices.h>
#include <data/AuthUser.h>
class HERP_AUTHORIZATION_MODULE_DLL_EXPORT AuthUserInput
    : public AuthParameter<AuthUser, list_auth_user_ptr> {
  QX_SERVICE_IX_PARAMETER_SERIALIZATION_HPP(AuthUserInput);
};
using AuthUserInputBase = AuthParameter<AuthUser, list_auth_user_ptr>;
HERP_REGISTER_HPP_HERP_AUTHORIZATION_MODULE(AuthUserInput, AuthUserInputBase, 0)
using auth_user_service_input_ptr = std::shared_ptr<AuthUserInput>;

class HERP_AUTHORIZATION_MODULE_DLL_EXPORT AuthUserOutput
    : public QxOutputParamaterBase<auth_user_ptr, list_auth_user_ptr> {
  QX_SERVICE_IX_PARAMETER_SERIALIZATION_HPP(AuthUserOutput);
};
using AuthUserOutputBase =
    QxOutputParamaterBase<auth_user_ptr, list_auth_user_ptr>;
HERP_REGISTER_HPP_HERP_AUTHORIZATION_MODULE(AuthUserOutput, AuthUserOutputBase,
                                            0)
using auth_user_service_output_ptr = std::shared_ptr<AuthUserOutput>;

typedef AuthServiceBase<AuthUserInput, AuthUserOutput, AuthUser, list_auth_user>
    auth_user_service_base_class;
class HERP_AUTHORIZATION_MODULE_DLL_EXPORT AuthUserService
    : public auth_user_service_base_class {

  QX_REGISTER_FRIEND_CLASS(AuthUserService)

public:
  AuthUserService()
      : auth_user_service_base_class(QStringLiteral("AuthUserService")) {
    ;
  }
  ~AuthUserService() override { ; }
};

HERP_REGISTER_HPP_HERP_AUTHORIZATION_MODULE(AuthUserService,
                                            auth_user_service_base_class, 0)
using auth_user_service_ptr = std::shared_ptr<AuthUserService>;
#endif
