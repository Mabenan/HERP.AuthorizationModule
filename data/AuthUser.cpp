/*
 * AuthUser.cpp
 *
 *  Created on: 25.02.2020
 *      Author: daniel
 */

#include <AuthUser.h>
#include <QxOrm_Impl.h>

QX_REGISTER_CPP(AuthUser)

namespace qx{
	template <> void register_class(QxClass<AuthUser> & t){
		t.setName("t_auth_user");
		t.id(& AuthUser::id, "id");
	}
}
