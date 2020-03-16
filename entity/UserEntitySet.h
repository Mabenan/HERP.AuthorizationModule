/*
 * UserEntitySet.h
 *
 *  Created on: 16.03.2020
 *      Author: doene
 */

#ifndef REPS_HERP_AUTHORIZATIONMODULE_ENTITY_USERENTITYSET_H_
#define REPS_HERP_AUTHORIZATIONMODULE_ENTITY_USERENTITYSET_H_

#include <HERP.AuthorizationModule.Precompiled.h>

class UserEntitySet: public ODataEntitySet {
public:
	UserEntitySet();
	~UserEntitySet();

	UserEntitySet(const UserEntitySet &userEntitySet);
	virtual void updateSet(QUrlQuery query, QVariantMap head) const;
	virtual void deleteSet(QUrlQuery query, QVariantMap head) const;
	virtual ODataEntitySet* clone() const;
	virtual ODataEntity* get(QMap<QString, QVariant> keys, QUrlQuery query,
			QVariantMap head);
	virtual void getSet(QUrlQuery query, QVariantMap head);
	virtual void insertSet(QUrlQuery query, QVariantMap head) const;
};

#endif /* REPS_HERP_AUTHORIZATIONMODULE_ENTITY_USERENTITYSET_H_ */
