/*
 * AuthObject.h
 *
 *  Created on: 25.02.2020
 *      Author: daniel
 */

#ifndef REPS_HERP_AUTHORIZATIONMODULE_DATA_AUTHOBJECT_H_
#define REPS_HERP_AUTHORIZATIONMODULE_DATA_AUTHOBJECT_H_

#include <QString>
#include <QxOrm.h>
class AuthObjectParam;

class AuthObject {
public:
	   typedef qx::QxCollection<int, std::shared_ptr<AuthObjectParam> > type_ListOfAuthObjectParam;
	long id;
	QString name;
	type_ListOfAuthObjectParam params;
public:
	AuthObject();
	virtual ~AuthObject();
};
QX_REGISTER_HPP(AuthObject, qx::trait::no_base_class_defined, 0)
#endif /* REPS_HERP_AUTHORIZATIONMODULE_DATA_AUTHOBJECT_H_ */
