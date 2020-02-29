/*
 * AuthObject.cpp
 *
 *  Created on: 25.02.2020
 *      Author: daniel
 */

#include <data/AuthObject.h>
#include <QxOrm_Impl.h>
#include <data/AuthObjectParam.h>
HERP_REGISTER_CPP_HERP_AUTHORIZATION_MODULE(AuthObject)

namespace qx {
template<> void register_class(QxClass<AuthObject> &t) {
	t.setName("t_auth_object");
	t.id(&AuthObject::m_id, "auth_object_id");
	t.data(&AuthObject::m_name, "name");
	t.relationOneToMany(& AuthObject::m_params, "list_auth_object_param", "auth_object_id");
}
}

AuthObject::AuthObject() {

	this->m_id = 0;
	this->m_name = "";

}

AuthObject::~AuthObject() {
}

