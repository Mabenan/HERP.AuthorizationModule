/*
 * AuthProvider.cpp
 *
 *  Created on: 02.03.2020
 *      Author: doene
 */

#include <command/AuthProvider.h>
#include <data/AuthUser.h>

QString AuthProvider::getName() const {
	return "HERP.AuthorizationModule";
}

int AuthProvider::isUserAuthorized(QString user, QString authObject,
		QMap<QString, QVariant> params, ApplicationServerInterface *app) {
	AuthUser *authUser = new AuthUser();
	authUser->name = user;
	if (qx::dao::exist(authUser)) {
		qx::dao::fetch_by_id_with_all_relation(authUser);
		if (params.contains("auth_guid")
				&& params["auth_guid"] == authUser->authGuid) {

			if(authObject == "ALL_USER"){
				return 0;
			}
			for (auth_group_ptr authGroup : authUser->m_auth_groups) {
				qx::dao::fetch_by_id_with_all_relation(authGroup);
				for (auth_object_ptr authObjectData : authGroup->m_auths_granted) {
					if (authObjectData->m_id == authObject)
						return 0;
				}
			}

		} else {
			return -1;
		}
		return 1;
	} else {
		return 1;
	}
	return -1;

}

AuthProvider::AuthProvider(QObject *parent) :
		AuthProviderInterface(parent) {
}

AuthProvider::~AuthProvider() {
}

#include "moc_authprovider.cpp"
