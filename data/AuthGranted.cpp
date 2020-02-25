/*
 * AuthGranted.cpp
 *
 *  Created on: 25.02.2020
 *      Author: daniel
 */

#include <data/AuthGranted.h>
#include <QxOrm_Impl.h>

QX_REGISTER_CPP(AuthGranted)

namespace qx{
	template <> void register_class(QxClass<AuthGranted> & t){
		t.setName("t_auth_granted");
		t.id(& AuthGranted::id, "id");
	}
}

AuthGranted::AuthGranted() {
	// TODO Auto-generated constructor stub

}

AuthGranted::~AuthGranted() {
	// TODO Auto-generated destructor stub
}

