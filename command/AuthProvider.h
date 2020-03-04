/*
 * AuthProvider.h
 *
 *  Created on: 02.03.2020
 *      Author: doene
 */

#ifndef REPS_HERP_AUTHORIZATIONMODULE_AUTHPROVIDER_H_
#define REPS_HERP_AUTHORIZATIONMODULE_AUTHPROVIDER_H_

#include <AuthProviderInterface.h>
#include <QObject>
class AuthProvider: public AuthProviderInterface {
	Q_OBJECT
public:
	AuthProvider(QObject *parent = nullptr);
	virtual ~AuthProvider();
	virtual QString getName() const;
	virtual int isUserAuthorized(QString user, QString authObject,
			QMap<QString, QVariant> params, ApplicationServerInterface *app);
};

#endif /* REPS_HERP_AUTHORIZATIONMODULE_AUTHPROVIDER_H_ */
