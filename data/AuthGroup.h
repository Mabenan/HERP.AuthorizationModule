/*
 * AuthGroup.h
 *
 *  Created on: 25.02.2020
 *      Author: daniel
 */

#ifndef REPS_HERP_AUTHORIZATIONMODULE_DATA_AUTHGROUP_H_
#define REPS_HERP_AUTHORIZATIONMODULE_DATA_AUTHGROUP_H_

#include <precompiled.h>
#include <QString>
class AuthUser;

class HERP_AUTHORIZATION_MODULE_DLL_EXPORT AuthGroup {
public:
	typedef std::vector<std::shared_ptr<AuthUser>> list_auth_user;
	long id;
	QString m_name;
	list_auth_user m_auth_users;
public:
	AuthGroup();
	virtual ~AuthGroup();
};
HERP_REGISTER_HPP_HERP_AUTHORIZATION_MODULE(AuthGroup, qx::trait::no_base_class_defined, 0)


typedef std::shared_ptr<AuthGroup> auth_group_ptr;
typedef std::vector<auth_group_ptr> list_auth_group;
typedef qx::QxCollection<long, auth_group_ptr> map_auth_group;
#endif /* REPS_HERP_AUTHORIZATIONMODULE_DATA_AUTHGROUP_H_ */
