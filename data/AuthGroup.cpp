/*
 * AuthGroup.cpp
 *
 *  Created on: 25.02.2020
 *      Author: daniel
 */

#include <data/AuthGroup.h>
#include <QxOrm_Impl.h>
#include <data/AuthUser.h>

HERP_REGISTER_CPP_HERP_AUTHORIZATION_MODULE(AuthGroup)

namespace qx{
	template <> void register_class(QxClass<AuthGroup> & t){
		t.setName("t_auth_group");
		t.id(& AuthGroup::m_name, "auth_group_id");
		t.relationManyToMany(& AuthGroup::m_auth_users, "list_auth_user","t_auth_user_group", "auth_group_id", "auth_user_id");
		t.relationManyToMany(& AuthGroup::m_auths_granted, "list_auth_granted", "t_auth_granted", "auth_group_id", "auth_object_id");
	}
}

AuthGroup::AuthGroup() {
	this->m_name = "";

}

AuthGroup::~AuthGroup() {
	// TODO Auto-generated destructor stub
}

