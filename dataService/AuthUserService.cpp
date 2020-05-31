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


REGISTER_AUTH(AuthUser,list_auth_user_ptr)
REGISTER_OUTPUT_PARAMETER_BASE(auth_user_ptr, list_auth_user_ptr)
REGISTER_AUTH_SERVICE_BASE(AuthUserInput, AuthUserOutput, AuthUser, list_auth_user)
REGISTER_SERVICE_BASE(AuthUserService)
namespace qx {

template <> void register_class(QxClass<AuthUserInput> &t) {
}

template <> void register_class(QxClass<AuthUserOutput> &t) {
}

} // namespace qx
