/*
 * UserEntitySet.cpp
 *
 *  Created on: 16.03.2020
 *      Author: doene
 */

#include <entity/UserEntitySet.h>
#include <entity/UserEntity.h>

void UserEntitySet::updateSet(QUrlQuery query, QVariantMap head) const {
}

void UserEntitySet::deleteSet(QUrlQuery query, QVariantMap head) const {
}

ODataEntitySet* UserEntitySet::clone() const {
	return new UserEntitySet(*this);
}

ODataEntity* UserEntitySet::get(QMap<QString, QVariant> keys, QUrlQuery query,
		QVariantMap head) {
}

void UserEntitySet::getSet(QUrlQuery query, QVariantMap head) {
}

UserEntitySet::UserEntitySet() : ODataEntitySet() {
	this->entity = new UserEntity();
	this->name = "RouteSet";
}

UserEntitySet::~UserEntitySet() {
}

UserEntitySet::UserEntitySet(const UserEntitySet &userEntitySet) : ODataEntitySet(userEntitySet){
}

void UserEntitySet::insertSet(QUrlQuery query, QVariantMap head) const {
}
