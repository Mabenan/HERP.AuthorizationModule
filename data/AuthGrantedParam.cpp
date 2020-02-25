/*
 * AuthGrantedParam.cpp
 *
 *  Created on: 25.02.2020
 *      Author: daniel
 */

#include <data/AuthGrantedParam.h>
#include <QxOrm_Impl.h>

QX_REGISTER_CPP(AuthGrantedParam)

namespace qx{
	template <> void register_class(QxClass<AuthGrantedParam> & t){
		t.setName("t_auth_granted_param");
		t.id(& AuthGrantedParam::id, "id");
	}
}

AuthGrantedParam::AuthGrantedParam() {
	// TODO Auto-generated constructor stub

}

AuthGrantedParam::~AuthGrantedParam() {
	// TODO Auto-generated destructor stub
}

