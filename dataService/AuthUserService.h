/*
 * AuthUser.h
 *
 *  Created on: 25.02.2020
 *      Author: daniel
 */

#ifndef REPS_HERP_AUTHORIZATIONMODULE_DATASERVICE_AUTHUSERSERVICE_H_
#define REPS_HERP_AUTHORIZATIONMODULE_DATASERVICE_AUTHUSERSERVICE_H_

#include <HERP.AuthorizationModule.Precompiled.h>
#include <QString>
#include <QxService/IxParameter.h>
#include <QxService/QxService.h>
#include <QxServices.h>
#include <data/AuthUser.h>
class HERP_AUTHORIZATION_MODULE_DLL_EXPORT AuthUserInput
    : public qx::service::IxParameter {
  QX_SERVICE_IX_PARAMETER_SERIALIZATION_HPP(AuthUserInput);

public:
  AuthUserInput() : IxParameter() {}
  ~AuthUserInput() override {}
  long id{0};
  auth_user_ptr user;
};
HERP_REGISTER_HPP_HERP_AUTHORIZATION_MODULE(AuthUserInput,
                                            qx::service::IxParameter, 0)
using auth_user_service_input_ptr = std::shared_ptr<AuthUserInput>;

class HERP_AUTHORIZATION_MODULE_DLL_EXPORT AuthUserOutput
    : public qx::service::IxParameter {
  QX_SERVICE_IX_PARAMETER_SERIALIZATION_HPP(AuthUserOutput);

public:
  auth_user_ptr user;
  list_auth_user list_of_users;
};
HERP_REGISTER_HPP_HERP_AUTHORIZATION_MODULE(AuthUserOutput,
                                            qx::service::IxParameter, 0)
using auth_user_service_output_ptr = std::shared_ptr<AuthUserOutput>;

typedef qx::service::QxService<AuthUserInput, AuthUserOutput>
    auth_user_service_base_class;
class HERP_AUTHORIZATION_MODULE_DLL_EXPORT AuthUserService
    : public auth_user_service_base_class {
public:
    AuthUserService() : auth_user_service_base_class(QStringLiteral("AuthUserService")) { ; }
  ~AuthUserService() override { ; }
  void insert();
  void update();
  void remove();
  void remove_all();
  void fetch_by_id();
  void fetch_all();
  void get_by_criteria();
};

HERP_REGISTER_HPP_HERP_AUTHORIZATION_MODULE(AuthUserService,
                                            qx::service::IxService, 0)
using auth_user_service_ptr = std::shared_ptr<AuthUserService>;
#endif
