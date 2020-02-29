/*
 * AuthObjectParam.h
 *
 *  Created on: 25.02.2020
 *      Author: daniel
 */

#ifndef REPS_HERP_AUTHORIZATIONMODULE_DATA_AUTHOBJECTPARAM_H_
#define REPS_HERP_AUTHORIZATIONMODULE_DATA_AUTHOBJECTPARAM_H_

#include <precompiled.h>
#include <QxOrm.h>
#include <data/AuthObject.h>

class HERP_AUTHORIZATION_MODULE_DLL_EXPORT AuthObjectParam {
public:
	long m_id;
	auth_object_ptr m_auth_object;
public:
	AuthObjectParam();
	virtual ~AuthObjectParam();
};
HERP_REGISTER_HPP_HERP_AUTHORIZATION_MODULE(AuthObjectParam, qx::trait::no_base_class_defined, 0)

typedef std::shared_ptr<AuthObjectParam> auth_object_param_ptr;
typedef std::vector<auth_object_param_ptr> list_auth_object_param;
typedef qx::QxCollection<long, auth_object_param_ptr> map_auth_object_param;
#endif /* REPS_HERP_AUTHORIZATIONMODULE_DATA_AUTHOBJECTPARAM_H_ */
