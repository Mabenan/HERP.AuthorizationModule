/*
 * AuthObjectParam.cpp
 *
 *  Created on: 25.02.2020
 *      Author: daniel
 */

#include <data/AuthObjectParam.h>
#include <data/AuthObject.h>
#include <QxOrm_Impl.h>

HERP_REGISTER_CPP_HERP_AUTHORIZATION_MODULE(AuthObjectParam)

namespace qx{
	template <> void register_class(QxClass<AuthObjectParam> & t){
		t.setName("t_auth_object_param");
		t.id(& AuthObjectParam::m_id, "auth_object_param_id");
        t.relationManyToOne(& AuthObjectParam::m_auth_object, "auth_object_id");
	}
}

AuthObjectParam::AuthObjectParam() {
	// TODO Auto-generated constructor stub

}

AuthObjectParam::~AuthObjectParam() {
	// TODO Auto-generated destructor stub
}

