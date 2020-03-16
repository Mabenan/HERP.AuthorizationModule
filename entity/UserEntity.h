/*
 * UserEntity.h
 *
 *  Created on: 16.03.2020
 *      Author: doene
 */

#ifndef REPS_HERP_AUTHORIZATIONMODULE_ENTITY_USERENTITY_H_
#define REPS_HERP_AUTHORIZATIONMODULE_ENTITY_USERENTITY_H_

#include <HERP.AuthorizationModule.Precompiled.h>

class UserEntity: public ODataEntity {
public:
	UserEntity();
	~UserEntity();
	UserEntity(const UserEntity &userEntity);
	virtual void deleteEntity(QMap<QString, QVariant> keys, QUrlQuery query,
			QVariantMap head) const;
	virtual ODataEntity* clone() const;
	virtual void insert(QMap<QString, QVariant> keys, QUrlQuery query,
			QVariantMap head) const;
	virtual void get(QMap<QString, QVariant> keys, QUrlQuery query,
			QVariantMap head);
	virtual QString getDescription();
	virtual void update(QMap<QString, QVariant> keys, QUrlQuery query,
			QVariantMap head) const;
};

#endif /* REPS_HERP_AUTHORIZATIONMODULE_ENTITY_USERENTITY_H_ */
