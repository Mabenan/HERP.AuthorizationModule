/*
 * AuthObject.cpp
 *
 *  Created on: 25.02.2020
 *      Author: daniel
 */

#include <data/AuthObject.h>
#include <QxOrm_Impl.h>

QX_REGISTER_CPP(AuthObject)

namespace qx {
template<> void register_class(QxClass<AuthObject> &t) {
	qx::IxDataMember *pData = NULL;
	Q_UNUSED(pData);
	qx::IxSqlRelation *pRelation = NULL;
	Q_UNUSED(pRelation);
	qx::IxFunction *pFct = NULL;
	Q_UNUSED(pFct);
	qx::IxValidator *pValidator = NULL;
	Q_UNUSED(pValidator);
	t.setName("t_auth_object");
	t.id(&AuthObject::id, "id");
	t.data(&AuthObject::name, "name");
	pRelation = t.relationOneToMany(&AuthObject::params, "Params",
			"AuthObjectParam", 0);
	pRelation->getDataMember()->setName("params");
}
}

AuthObject::AuthObject() {

	this->id = 0;
	this->name = "";

}

AuthObject::~AuthObject() {
}

