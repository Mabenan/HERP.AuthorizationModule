/*
 * AuthGroup.h
 *
 *  Created on: 25.02.2020
 *      Author: daniel
 */

#ifndef REPS_HERP_AUTHORIZATIONMODULE_DATA_AUTHGROUP_H_
#define REPS_HERP_AUTHORIZATIONMODULE_DATA_AUTHGROUP_H_

#include <QString>
#include <data/AuthObject.h>
#include <HERP.AuthorizationModule.Precompiled.h>
class AuthUser;

class HERP_AUTHORIZATION_MODULE_DLL_EXPORT AuthGroup  {
public:
    using list_auth_user = std::vector<std::shared_ptr<AuthUser> >;
    QString m_name;
    list_auth_user m_auth_users;
    list_auth_object m_auths_granted;
public:
    AuthGroup();
    virtual ~AuthGroup();
};
QX_REGISTER_PRIMARY_KEY(AuthGroup, QString, m_name);
HERP_REGISTER_HPP_HERP_AUTHORIZATION_MODULE(AuthGroup, qx::trait::no_base_class_defined, 0)


using auth_group_ptr = std::shared_ptr<AuthGroup>;
using list_auth_group = std::vector<auth_group_ptr>;
typedef qx::QxCollection<long, auth_group_ptr> map_auth_group;
#endif /* REPS_HERP_AUTHORIZATIONMODULE_DATA_AUTHGROUP_H_ */
