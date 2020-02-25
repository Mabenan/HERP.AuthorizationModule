/*
 * AuthGrantedParam.h
 *
 *  Created on: 25.02.2020
 *      Author: daniel
 */

#ifndef REPS_HERP_AUTHORIZATIONMODULE_DATA_AUTHGRANTEDPARAM_H_
#define REPS_HERP_AUTHORIZATIONMODULE_DATA_AUTHGRANTEDPARAM_H_

#include <QxOrm.h>
class AuthGrantedParam {
public:
	long id;
public:
	AuthGrantedParam();
	virtual ~AuthGrantedParam();
};
QX_REGISTER_HPP(AuthGrantedParam, qx::trait::no_base_class_defined, 0)

#endif /* REPS_HERP_AUTHORIZATIONMODULE_DATA_AUTHGRANTEDPARAM_H_ */
