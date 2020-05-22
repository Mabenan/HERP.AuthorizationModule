/*
 * AuthObject.cpp
 *
 *  Created on: 25.02.2020
 *      Author: daniel
 */

#include <data/AuthObject.h>
#include <QxOrm_Impl.h>
#include <data/AuthGroup.h>
HERP_REGISTER_CPP_HERP_AUTHORIZATION_MODULE(AuthObject)

namespace qx {
template<> void register_class(QxClass<AuthObject> &t) {
	t.setName("t_auth_object");
	t.id(&AuthObject::m_id, "auth_object_id");
	t.relationManyToMany(& AuthObject::m_auth_groups, "list_auth_groups", "t_auth_granted", "auth_object_id", "auth_group_id");
}
}

AuthObject::AuthObject() {

	this->m_id = "";

}

AuthObject::~AuthObject() = default;

