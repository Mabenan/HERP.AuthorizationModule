/*
 * AuthUser.h
 *
 *  Created on: 25.02.2020
 *      Author: daniel
 */

#ifndef REPS_HERP_AUTHORIZATIONMODULE_DATA_AUTHUSER_H_
#define REPS_HERP_AUTHORIZATIONMODULE_DATA_AUTHUSER_H_

#include <QxOrm.h>
#include <QString>

class AuthUser{

public:
	long id;

};

QX_REGISTER_HPP(AuthUser, qx::trait::no_base_class_defined, 0)

#endif /* REPS_HERP_AUTHORIZATIONMODULE_DATA_AUTHUSER_H_ */
