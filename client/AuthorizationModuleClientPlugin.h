/*
 * AuthorizationModulePlugin.h
 *
 *  Created on: 29.02.2020
 *      Author: doene
 */

#ifndef REPS_HERP_AUTHORIZATIONMODULE_AUTHORIZATIONMODULEPLUGIN_H_
#define REPS_HERP_AUTHORIZATIONMODULE_AUTHORIZATIONMODULEPLUGIN_H_

#include <ApplicationClientPluginInterface.h>
#include <HERP.AuthorizationModule.Precompiled.h>
#include <userdashboarditem.h>
class HERP_AUTHORIZATION_MODULE_DLL_EXPORT AuthorizationModuleClientPlugin: public ApplicationClientPluginInterface {

    Q_OBJECT
    Q_PLUGIN_METADATA(IID ApplicationClientPluginInterface_iid FILE "HERP.AuthorizationModulePlugin.Client.json")
    Q_INTERFACES(ApplicationClientPluginInterface)
private:
    UserDashboardItem * dashboard;
public:
    AuthorizationModuleClientPlugin(QObject *parent = nullptr);
    ~AuthorizationModuleClientPlugin() override;
    void init(ApplicationClientInterface *app) override;
    void install(ApplicationClientInterface *app) override;

    // ApplicationClientPluginInterface interface
public:
    const QString getName() override;
};

#endif /* REPS_HERP_AUTHORIZATIONMODULE_AUTHORIZATIONMODULEPLUGIN_H_ */
