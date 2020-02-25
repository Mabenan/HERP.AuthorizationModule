/*
 * AuthGroup.h
 *
 *  Created on: 25.02.2020
 *      Author: daniel
 */

#ifndef REPS_HERP_AUTHORIZATIONMODULE_DATA_AUTHGROUP_H_
#define REPS_HERP_AUTHORIZATIONMODULE_DATA_AUTHGROUP_H_

#include <QxOrm.h>
class AuthGroup {
public:
	long id;
public:
	AuthGroup();
	virtual ~AuthGroup();
};
QX_REGISTER_HPP(AuthGroup, qx::trait::no_base_class_defined, 0)

#endif /* REPS_HERP_AUTHORIZATIONMODULE_DATA_AUTHGROUP_H_ */
