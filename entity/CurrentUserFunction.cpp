/*
 * CurrentUserFunction.cpp
 *
 *  Created on: 16.03.2020
 *      Author: doene
 */

#include <entity/CurrentUserFunction.h>
#include <data/AuthUser.h>
#include <entity/UserEntitySet.h>
#include <entity/UserEntity.h>

CurrentUserFunction::CurrentUserFunction(QObject *parent) : ODataFunction(parent){
	this->entitySetToReturn = new UserEntitySet();
	this->name = "CurrentUser";
}

CurrentUserFunction::~CurrentUserFunction() {
}

ODataEntity* CurrentUserFunction::call(QMap<QString, QVariant> keys,
		QUrlQuery query, QVariantMap head) const {
	UserEntity * userEntity = new UserEntity();
	QString auth_guid = head["auth_guid"].toString();
	QString user = head["user"].toString();
	AuthUser * userObject = new AuthUser();
	userObject->name = user;
	if(qx::dao::exist(userObject)){
		qx::dao::fetch_by_id(userObject);
		if(userObject->authGuid == auth_guid){
			userEntity->data.insert("name", userObject->name);
		}else{
			userEntity->data.insert("name", "");
		}
	}else{
		userEntity->data.insert("name", "");
	}
	return userEntity;
}
