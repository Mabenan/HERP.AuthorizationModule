/*
 * WebAuthorization.h
 *
 *  Created on: 13.03.2020
 *      Author: drichte
 */

#ifndef REPS_HERP_AUTHORIZATIONMODULE_WEBSERVICES_WEBAUTHORIZATION_H_
#define REPS_HERP_AUTHORIZATIONMODULE_WEBSERVICES_WEBAUTHORIZATION_H_

#include <WebInterface.h>
#include "HERP.AuthorizationModule.Precompiled.h"

class WebAuthorization: public WebInterface {

	Q_OBJECT
public:
	WebAuthorization(QObject *parent = nullptr);
	virtual ~WebAuthorization();
	QString getName() const;
	QString getRoute(ApplicationServerInterface *app);
    virtual void execute(qx::QxHttpRequest  & request, qx::QxHttpResponse & response, ApplicationServerInterface * app);

};

#endif /* REPS_HERP_AUTHORIZATIONMODULE_WEBSERVICES_WEBAUTHORIZATION_H_ */
