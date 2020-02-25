/*
 * AuthObjectParam.h
 *
 *  Created on: 25.02.2020
 *      Author: daniel
 */

#ifndef REPS_HERP_AUTHORIZATIONMODULE_DATA_AUTHOBJECTPARAM_H_
#define REPS_HERP_AUTHORIZATIONMODULE_DATA_AUTHOBJECTPARAM_H_

#include <QxOrm.h>
class AuthObjectParam {
public:
	long id;

public:
	AuthObjectParam();
	virtual ~AuthObjectParam();
};
QX_REGISTER_HPP(AuthObjectParam, qx::trait::no_base_class_defined, 0)

#endif /* REPS_HERP_AUTHORIZATIONMODULE_DATA_AUTHOBJECTPARAM_H_ */
