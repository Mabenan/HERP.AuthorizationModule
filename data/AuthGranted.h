/*
 * AuthGranted.h
 *
 *  Created on: 25.02.2020
 *      Author: daniel
 */

#ifndef REPS_HERP_AUTHORIZATIONMODULE_DATA_AUTHGRANTED_H_
#define REPS_HERP_AUTHORIZATIONMODULE_DATA_AUTHGRANTED_H_

#include <precompiled.h>
class HERP_AUTHORIZATION_MODULE_DLL_EXPORT AuthGranted {
public:
	long id;
public:
	AuthGranted();
	virtual ~AuthGranted();
};
HERP_REGISTER_HPP_HERP_AUTHORIZATION_MODULE(AuthGranted, qx::trait::no_base_class_defined, 0)

#endif /* REPS_HERP_AUTHORIZATIONMODULE_DATA_AUTHGRANTED_H_ */
