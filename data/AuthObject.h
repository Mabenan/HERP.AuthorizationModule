/*
 * AuthObject.h
 *
 *  Created on: 25.02.2020
 *      Author: daniel
 */

#ifndef REPS_HERP_AUTHORIZATIONMODULE_DATA_AUTHOBJECT_H_
#define REPS_HERP_AUTHORIZATIONMODULE_DATA_AUTHOBJECT_H_
#include <precompiled.h>
#include <QString>
#include <QxOrm.h>
class AuthObjectParam;

class HERP_AUTHORIZATION_MODULE_DLL_EXPORT AuthObject {
public:
	   typedef std::shared_ptr<AuthObjectParam> auth_object_param_ptr;
	   typedef std::vector<auth_object_param_ptr> list_auth_object_param;
	long m_id;
	QString m_name;
	list_auth_object_param m_params;
public:
	AuthObject();
	virtual ~AuthObject();
};
HERP_REGISTER_HPP_HERP_AUTHORIZATION_MODULE(AuthObject, qx::trait::no_base_class_defined, 0)


typedef std::shared_ptr<AuthObject> auth_object_ptr;

typedef std::vector<auth_object_ptr> list_auth_object;
typedef qx::QxCollection<long, auth_object_ptr> map_auth_object;
#endif /* REPS_HERP_AUTHORIZATIONMODULE_DATA_AUTHOBJECT_H_ */
