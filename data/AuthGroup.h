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
	typedef std::vector<std::shared_ptr<AuthUser>> list_auth_user;
	QString m_name;
	list_auth_user m_auth_users;
	list_auth_object m_auths_granted;
public:
	AuthGroup();
	virtual ~AuthGroup();
};
QX_REGISTER_PRIMARY_KEY(AuthGroup, QString);
HERP_REGISTER_HPP_HERP_AUTHORIZATION_MODULE(AuthGroup, qx::trait::no_base_class_defined, 0)


typedef std::shared_ptr<AuthGroup> auth_group_ptr;
typedef std::vector<auth_group_ptr> list_auth_group;
typedef qx::QxCollection<long, auth_group_ptr> map_auth_group;
#endif /* REPS_HERP_AUTHORIZATIONMODULE_DATA_AUTHGROUP_H_ */
