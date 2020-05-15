/*
 * AuthUser.h
 *
 *  Created on: 25.02.2020
 *      Author: daniel
 */

#ifndef REPS_HERP_AUTHORIZATIONMODULE_DATA_AUTHUSER_H_
#define REPS_HERP_AUTHORIZATIONMODULE_DATA_AUTHUSER_H_

#include <QString>
#include <data/AuthGroup.h>
#include <HERP.AuthorizationModule.Precompiled.h>
class HERP_AUTHORIZATION_MODULE_DLL_EXPORT AuthUser{

public:
	QString name;
	QString authGuid;
	QString pass;
	list_auth_group m_auth_groups;
};
QX_REGISTER_PRIMARY_KEY(AuthUser, QString);
HERP_REGISTER_HPP_HERP_AUTHORIZATION_MODULE(AuthUser, qx::trait::no_base_class_defined, 0);

typedef std::shared_ptr<AuthUser> auth_user_ptr;
typedef std::vector<auth_user_ptr> list_auth_user;
typedef qx::QxCollection<long, auth_user_ptr> map_auth_user;
#endif /* REPS_HERP_AUTHORIZATIONMODULE_DATA_AUTHUSER_H_ */
