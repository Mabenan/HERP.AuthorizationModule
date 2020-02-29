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
		t.id(& AuthGroup::id, "auth_group_id");
		t.data(& AuthGroup::m_name, "name");
		t.relationManyToMany(& AuthGroup::m_auth_users, "list_auth_user","t_auth_user_group", "auth_group_id", "auth_user_id");
	}
}

AuthGroup::AuthGroup() {
	// TODO Auto-generated constructor stub

}

AuthGroup::~AuthGroup() {
	// TODO Auto-generated destructor stub
}

