/*
 * AuthUser.h
 *
 *  Created on: 25.02.2020
 *      Author: daniel
 */

#ifndef REPS_HERP_AUTHORIZATIONMODULE_DATA_AUTHUSER_H_
#define REPS_HERP_AUTHORIZATIONMODULE_DATA_AUTHUSER_H_

#include <QString>
#include <AuthGroup.h>

#include <AuthUserToken.h>
class HERP_AUTHORIZATION_MODULE_DLL_EXPORT AuthUser : public qx::IxPersistable{

    QX_PERSISTABLE_HPP(AuthUser)
public:
    QString name;
    QString pass;
    list_auth_group m_auth_groups;
    list_auth_user_token m_auth_user_tokens;
};
QX_REGISTER_PRIMARY_KEY(AuthUser, QString, name);
HERP_REGISTER_HPP_HERP_AUTHORIZATION_MODULE(AuthUser, qx::trait::no_base_class_defined, 0);

using auth_user_ptr = std::shared_ptr<AuthUser>;
using list_auth_user = qx::QxCollection<QString, auth_user_ptr>;
typedef std::shared_ptr<list_auth_user> list_auth_user_ptr;
typedef qx::QxCollection<QString, auth_user_ptr> map_auth_user;
typedef std::shared_ptr<map_auth_user> map_auth_user_ptr;
#endif /* REPS_HERP_AUTHORIZATIONMODULE_DATA_AUTHUSER_H_ */
