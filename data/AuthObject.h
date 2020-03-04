/*
 * AuthObject.h
 *
 *  Created on: 25.02.2020
 *      Author: daniel
 */

#ifndef REPS_HERP_AUTHORIZATIONMODULE_DATA_AUTHOBJECT_H_
#define REPS_HERP_AUTHORIZATIONMODULE_DATA_AUTHOBJECT_H_
#include <HERP.AuthorizationModule.Precompiled.h>
#include <QString>
#include <QxOrm.h>
class AuthGroup;

class HERP_AUTHORIZATION_MODULE_DLL_EXPORT AuthObject {
public:
	typedef std::shared_ptr<AuthGroup> auth_group_ptr;
	typedef std::vector<auth_group_ptr> list_auth_group;
	QString m_id;
	list_auth_group m_auth_groups;
public:
	AuthObject();
	virtual ~AuthObject();
};
QX_REGISTER_PRIMARY_KEY(AuthObject, QString);
HERP_REGISTER_HPP_HERP_AUTHORIZATION_MODULE(AuthObject, qx::trait::no_base_class_defined, 0);


typedef std::shared_ptr<AuthObject> auth_object_ptr;

typedef std::vector<auth_object_ptr> list_auth_object;
typedef qx::QxCollection<long, auth_object_ptr> map_auth_object;
#endif /* REPS_HERP_AUTHORIZATIONMODULE_DATA_AUTHOBJECT_H_ */
