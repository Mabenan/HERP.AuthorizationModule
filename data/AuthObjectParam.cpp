/*
 * AuthObjectParam.cpp
 *
 *  Created on: 25.02.2020
 *      Author: daniel
 */

#include <data/AuthObjectParam.h>

#include <QxOrm_Impl.h>

QX_REGISTER_CPP(AuthObjectParam)

namespace qx{
	template <> void register_class(QxClass<AuthObjectParam> & t){
		t.setName("t_auth_object_param");
		t.id(& AuthObjectParam::id, "id");
	}
}

AuthObjectParam::AuthObjectParam() {
	// TODO Auto-generated constructor stub

}

AuthObjectParam::~AuthObjectParam() {
	// TODO Auto-generated destructor stub
}

