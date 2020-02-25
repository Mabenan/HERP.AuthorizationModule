/*
 * AuthGroup.cpp
 *
 *  Created on: 25.02.2020
 *      Author: daniel
 */

#include <data/AuthGroup.h>
#include <QxOrm_Impl.h>

QX_REGISTER_CPP(AuthGroup)

namespace qx{
	template <> void register_class(QxClass<AuthGroup> & t){
		t.setName("t_auth_group");
		t.id(& AuthGroup::id, "id");
	}
}

AuthGroup::AuthGroup() {
	// TODO Auto-generated constructor stub

}

AuthGroup::~AuthGroup() {
	// TODO Auto-generated destructor stub
}

