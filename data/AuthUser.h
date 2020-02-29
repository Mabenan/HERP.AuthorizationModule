/*
 * AuthUser.h
 *
 *  Created on: 25.02.2020
 *      Author: daniel
 */

#ifndef REPS_HERP_AUTHORIZATIONMODULE_DATA_AUTHUSER_H_
#define REPS_HERP_AUTHORIZATIONMODULE_DATA_AUTHUSER_H_

#include <precompiled.h>
#include <QString>
#include <data/AuthGroup.h>
class HERP_AUTHORIZATION_MODULE_DLL_EXPORT AuthUser{

public:
	long id;
	list_auth_group m_auth_groups;
};

HERP_REGISTER_HPP_HERP_AUTHORIZATION_MODULE(AuthUser, qx::trait::no_base_class_defined, 0)

typedef std::shared_ptr<AuthUser> auth_user_param_ptr;
typedef std::vector<auth_user_param_ptr> list_auth_user_param;
typedef qx::QxCollection<long, auth_user_param_ptr> map_auth_user_param;
#endif /* REPS_HERP_AUTHORIZATIONMODULE_DATA_AUTHUSER_H_ */
