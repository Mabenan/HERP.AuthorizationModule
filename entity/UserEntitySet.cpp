/*
 * UserEntitySet.cpp
 *
 *  Created on: 16.03.2020
 *      Author: doene
 */

#include <entity/UserEntitySet.h>
#include <entity/UserEntity.h>
#include <data/AuthUser.h>

void UserEntitySet::updateSet(QUrlQuery query, QVariantMap head) const {
}

void UserEntitySet::deleteSet(QUrlQuery query, QVariantMap head) const {
}

ODataEntitySet* UserEntitySet::clone() const {
	return new UserEntitySet(*this);
}

ODataEntity* UserEntitySet::get(QMap<QString, QVariant> keys, QUrlQuery query,
		QVariantMap head) {
	UserEntity *entity = new UserEntity();
	QVariant name = keys["name"];
	qDebug() << name.toString();
	if (name.toString() == "Current") {
		QString auth_guid = head["auth_guid"].toString();
		QString user = head["user"].toString();
		AuthUser *userObject = new AuthUser();
		userObject->name = user;
		if (qx::dao::exist(userObject)) {
			qx::dao::fetch_by_id(userObject);
			if (userObject->authGuid == auth_guid) {
				entity->data.insert("name", userObject->name);
			} else {
				entity->data.insert("name", QString("not logged in"));
			}
		} else {
			entity->data.insert("name", QString("not logged in"));
		}
	} else {
		QString auth_guid = head["auth_guid"].toString();
		QString user = head["user"].toString();
		AuthUser *userObject = new AuthUser();
		userObject->name = user;
		if (qx::dao::exist(userObject)) {
			qx::dao::fetch_by_id(userObject);
			if (userObject->authGuid == auth_guid) {
				if (name.toString() == userObject->name) {
					entity->data.insert("name", userObject->name);
				} else {
					entity->data.insert("name", QString("not logged in"));
				}
			} else {
				entity->data.insert("name", QString("not logged in"));

			}
		} else {
			entity->data.insert("name", QString("not logged in"));
		}
	}
	return entity;
}

void UserEntitySet::getSet(QUrlQuery query, QVariantMap head) {
}

UserEntitySet::UserEntitySet() :
		ODataEntitySet() {
	this->entity = new UserEntity();
	this->name = "UserSet";
}

UserEntitySet::~UserEntitySet() {
}

UserEntitySet::UserEntitySet(const UserEntitySet &userEntitySet) :
		ODataEntitySet(userEntitySet) {
}

void UserEntitySet::insertSet(QUrlQuery query, QVariantMap head) const {
}
