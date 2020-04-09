/*
 * UserEntity.cpp
 *
 *  Created on: 16.03.2020
 *      Author: doene
 */

#include <entity/UserEntity.h>
#include <data/AuthUser.h>

void UserEntity::deleteEntity(QMap<QString, QVariant> keys, QUrlQuery query,
		QVariantMap head) const {
}

ODataEntity* UserEntity::clone() const {
	return new UserEntity(*this);
}

void UserEntity::insert(QMap<QString, QVariant> keys, QUrlQuery query,
		QVariantMap head) const {
}

void UserEntity::get(QMap<QString, QVariant> keys, QUrlQuery query,
		QVariantMap head) {
}

QString UserEntity::getDescription() {
	return this->description;
}

UserEntity::UserEntity() :
		ODataEntity() {
	this->name = "User";
	this->description = "User";
	this->property.insert("name", new ODataProperty("Edm.String", true));
	this->property.insert("pass", new ODataProperty("Edm.String", false));
	this->data.insert("name", "");
	this->data.insert("pass", "");
}
UserEntity::UserEntity(const UserEntity &userEntity) :
		ODataEntity(userEntity) {
}

UserEntity::~UserEntity() {
}

void UserEntity::update(QMap<QString, QVariant> keys, QUrlQuery query,
		QVariantMap head) const {
	if(this->data.contains("pass")){
		QString password = std::get<QVariant>(this->data["pass"]).toString();
		QString passwordHash = QString(QCryptographicHash::hash(password.toUtf8(),QCryptographicHash::Sha256).toHex());

		QString auth_guid = head["auth_guid"].toString();
		QString user = head["user"].toString();
		AuthUser *userObject = new AuthUser();
		userObject->name = user;
		if (qx::dao::exist(userObject)) {
			qx::dao::fetch_by_id(userObject);
			if (userObject->authGuid == auth_guid) {
				if(userObject->pass != passwordHash){
					userObject->pass = passwordHash;
					qx::dao::save(userObject);
				}
			} else {
			}
		}
	}
}

