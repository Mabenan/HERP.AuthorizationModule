/*
 * AuthUser.cpp
 *
 *  Created on: 25.02.2020
 *      Author: daniel
 */

#include <data/AuthUser.h>
#include <QxOrm_Impl.h>

HERP_REGISTER_CPP_HERP_AUTHORIZATION_MODULE(AuthUser)

namespace qx{
	template <> void register_class(QxClass<AuthUser> & t){
		t.setName("t_auth_user");
		t.id(& AuthUser::name, "auth_user_name");
		t.data(& AuthUser::pass, "pass");
		t.data(& AuthUser::authGuid,"auth_guid");
		t.relationManyToMany(& AuthUser::m_auth_groups, "list_auth_group", "t_auth_user_group", "auth_user_name", "auth_group_id");
	}
}
