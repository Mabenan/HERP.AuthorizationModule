/*
 * CurrentUserFunction.h
 *
 *  Created on: 16.03.2020
 *      Author: doene
 */

#ifndef REPS_HERP_AUTHORIZATIONMODULE_ENTITY_CURRENTUSERFUNCTION_H_
#define REPS_HERP_AUTHORIZATIONMODULE_ENTITY_CURRENTUSERFUNCTION_H_

#include <HERP.AuthorizationModule.Precompiled.h>

class CurrentUserFunction: public ODataFunction {
public:
	CurrentUserFunction(QObject * parent = nullptr);
	~CurrentUserFunction();
	virtual ODataEntity* call(QMap<QString, QVariant> keys, QUrlQuery query,
			QVariantMap head) const;
};

#endif /* REPS_HERP_AUTHORIZATIONMODULE_ENTITY_CURRENTUSERFUNCTION_H_ */
