/*
 * AuthUser.cpp
 *
 *  Created on: 25.02.2020
 *      Author: daniel
 */

#include <QxOrm_Impl.h>
#include <dataService/AuthUserService.h>

#include <memory>

HERP_REGISTER_CPP_HERP_AUTHORIZATION_MODULE(AuthUserInput)
HERP_REGISTER_CPP_HERP_AUTHORIZATION_MODULE(AuthUserOutput)
HERP_REGISTER_CPP_HERP_AUTHORIZATION_MODULE(AuthUserService)

QX_SERVICE_IX_PARAMETER_SERIALIZATION_CPP(AuthUserInput)
QX_SERVICE_IX_PARAMETER_SERIALIZATION_CPP(AuthUserOutput)

namespace qx {

template <> void register_class(QxClass<AuthUserInput> &t) {
  t.data(&AuthUserInput::id, QStringLiteral("id"));
  t.data(&AuthUserInput::user, QStringLiteral("user"));
}

template <> void register_class(QxClass<AuthUserOutput> &t) {
  t.data(&AuthUserOutput::user, QStringLiteral("user"));
  t.data(&AuthUserOutput::list_of_users, QStringLiteral("list_of_users"));
}

template <> void register_class(QxClass<AuthUserService> &t) {
  t.fct_0<void>(std::mem_fn(&AuthUserService::insert),
                QStringLiteral("insert"));
  t.fct_0<void>(std::mem_fn(&AuthUserService::update),
                QStringLiteral("update"));
  t.fct_0<void>(std::mem_fn(&AuthUserService::remove),
                QStringLiteral("remove"));
  t.fct_0<void>(std::mem_fn(&AuthUserService::remove_all),
                QStringLiteral("remove_all"));
  t.fct_0<void>(std::mem_fn(&AuthUserService::fetch_by_id),
                QStringLiteral("fetch_by_id"));
  t.fct_0<void>(std::mem_fn(&AuthUserService::fetch_all),
                QStringLiteral("fetch_all"));
  t.fct_0<void>(std::mem_fn(&AuthUserService::get_by_criteria),
                QStringLiteral("get_by_criteria"));
}

} // namespace qx

#ifdef _APP_CLIENT

void AuthUserService::insert() {
  qx::service::execute_client(this, QStringLiteral("insert"));
}
void AuthUserService::update() {
  qx::service::execute_client(this, QStringLiteral("update"));
}
void AuthUserService::remove() {
  qx::service::execute_client(this, QStringLiteral("remove"));
}
void AuthUserService::remove_all() {
  qx::service::execute_client(this, QStringLiteral("remove_all"));
}
void AuthUserService::fetch_by_id() {
  qx::service::execute_client(this, QStringLiteral("fetch_by_id"));
}
void AuthUserService::fetch_all() {
  qx::service::execute_client(this, QStringLiteral("fetch_all"));
}
void AuthUserService::get_by_criteria() {
  qx::service::execute_client(this, QStringLiteral("get_by_criteria"));
}

#else // _APP_CLIENT

void AuthUserService::insert() {}

void AuthUserService::update() {}

void AuthUserService::remove() {}

void AuthUserService::remove_all() {}

void AuthUserService::fetch_by_id() {}

void AuthUserService::fetch_all() {
  list_auth_user users;
  qx::dao::fetch_all(users);
  auth_user_service_output_ptr output = std::make_shared<AuthUserOutput>();
  output->list_of_users = users;
  setOutputParameter(output);
  setMessageReturn(true);
}

void AuthUserService::get_by_criteria() {}

#endif // _APP_CLIENT
