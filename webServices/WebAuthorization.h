/*
 * WebAuthorization.h
 *
 *  Created on: 13.03.2020
 *      Author: drichte
 */

#ifndef REPS_HERP_AUTHORIZATIONMODULE_WEBSERVICES_WEBAUTHORIZATION_H_
#define REPS_HERP_AUTHORIZATIONMODULE_WEBSERVICES_WEBAUTHORIZATION_H_

#include <WebInterface.h>

class WebAuthorization: public WebInterface {
	Q_OBJECT
public:
	WebAuthorization(QObject *parent = nullptr);
	virtual ~WebAuthorization();
	virtual QString getName() const;
	virtual QString getRoute(ApplicationServerInterface *app);
	virtual QHttpServerResponse execute(const QHttpServerRequest *request,
			ApplicationServerInterface *app);
};

#endif /* REPS_HERP_AUTHORIZATIONMODULE_WEBSERVICES_WEBAUTHORIZATION_H_ */
