/*
 * AuthGrantedParam.h
 *
 *  Created on: 25.02.2020
 *      Author: daniel
 */

#ifndef REPS_HERP_AUTHORIZATIONMODULE_DATA_AUTHGRANTEDPARAM_H_
#define REPS_HERP_AUTHORIZATIONMODULE_DATA_AUTHGRANTEDPARAM_H_

#include <precompiled.h>
class HERP_AUTHORIZATION_MODULE_DLL_EXPORT AuthGrantedParam {
public:
	long id;
public:
	AuthGrantedParam();
	virtual ~AuthGrantedParam();
};
HERP_REGISTER_HPP_HERP_AUTHORIZATION_MODULE(AuthGrantedParam, qx::trait::no_base_class_defined, 0)

#endif /* REPS_HERP_AUTHORIZATIONMODULE_DATA_AUTHGRANTEDPARAM_H_ */
