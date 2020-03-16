/*
 * UserEntity.cpp
 *
 *  Created on: 16.03.2020
 *      Author: doene
 */

#include <entity/UserEntity.h>

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

UserEntity::UserEntity() : ODataEntity() {
	this->name = "User";
	this->description = "User";
	this->property.insert("name", new ODataProperty("Edm.String", true));
}
UserEntity::UserEntity(const UserEntity &userEntity) : ODataEntity(userEntity) {
}

UserEntity::~UserEntity() {
}

void UserEntity::update(QMap<QString, QVariant> keys, QUrlQuery query,
		QVariantMap head) const {
}
