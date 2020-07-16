/*
 * AuthorizationModulePlugin.h
 *
 *  Created on: 29.02.2020
 *      Author: doene
 */

#ifndef REPS_HERP_AUTHORIZATIONMODULE_AUTHORIZATIONMODULEPLUGIN_H_
#define REPS_HERP_AUTHORIZATIONMODULE_AUTHORIZATIONMODULEPLUGIN_H_

#include <ApplicationServerPluginInterface.h>


class HERP_AUTHORIZATION_MODULE_DLL_EXPORT AuthorizationModulePlugin: public ApplicationServerPluginInterface {

    Q_OBJECT
    Q_PLUGIN_METADATA(IID ApplicationServerPluginInterface_iid FILE "HERP.AuthorizationModulePlugin.json")
    Q_INTERFACES(ApplicationServerPluginInterface)
public:
	AuthorizationModulePlugin(QObject *parent = nullptr);
	~AuthorizationModulePlugin() override;
	void init(ApplicationServerInterface *app) override;
	void install(ApplicationServerInterface *app) override;
};

#endif /* REPS_HERP_AUTHORIZATIONMODULE_AUTHORIZATIONMODULEPLUGIN_H_ */
