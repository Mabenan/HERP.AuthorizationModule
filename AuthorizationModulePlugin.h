/*
 * AuthorizationModulePlugin.h
 *
 *  Created on: 29.02.2020
 *      Author: doene
 */

#ifndef REPS_HERP_AUTHORIZATIONMODULE_AUTHORIZATIONMODULEPLUGIN_H_
#define REPS_HERP_AUTHORIZATIONMODULE_AUTHORIZATIONMODULEPLUGIN_H_

#include <ApplicationServerPluginInterface.h>
#include <precompiled.h>

class HERP_AUTHORIZATION_MODULE_DLL_EXPORT AuthorizationModulePlugin: public ApplicationServerPluginInterface {

    Q_OBJECT
    Q_PLUGIN_METADATA(IID ApplicationServerPluginInterface_iid FILE "HERP.AuthorizationModulePlugin.json")
    Q_INTERFACES(ApplicationServerPluginInterface)
public:
	AuthorizationModulePlugin(QObject *parent = nullptr);
	virtual ~AuthorizationModulePlugin();
	virtual void init(ApplicationServerInterface *app);
	virtual void install(ApplicationServerInterface *app);
};

#endif /* REPS_HERP_AUTHORIZATIONMODULE_AUTHORIZATIONMODULEPLUGIN_H_ */
