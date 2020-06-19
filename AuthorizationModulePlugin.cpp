/*
 * AuthorizationModulePlugin.cpp
 *
 *  Created on: 29.02.2020
 *      Author: doene
 */

#include <AuthorizationModulePlugin.h>
#include <command/ListAuthGroupCommand.h>
#include <data/AuthGroup.h>
#include <data/AuthObject.h>
#include <data/AuthServiceMethod.h>
#include <data/AuthUser.h>
#include <command/AuthProvider.h>
#include <command/addusercommand.h>
#include <webServices/WebAuthorization.h>
#include <dataService/authservicebase.h>
AuthorizationModulePlugin::AuthorizationModulePlugin(QObject *parent) : ApplicationServerPluginInterface(parent) {
    // TODO Auto-generated constructor stub

}

AuthorizationModulePlugin::~AuthorizationModulePlugin() {
    // TODO Auto-generated destructor stub
}

void AuthorizationModulePlugin::init(ApplicationServerInterface *app) {
    ApplicationServerInterfaceProvider::SetApp(app);
    app->registerCommand(new ListAuthGroupCommand(this));
    app->registerCommand(new AddUserCommand(this));
    app->registerAuthProvider(new AuthProvider(this));
    app->registerWebInterface(new WebAuthorization(this));

}
void AuthorizationModulePlugin::install(ApplicationServerInterface *  /*app*/){
    qx::dao::create_table<AuthGroup>();
    qx::dao::create_table<AuthUser>();
    qx::dao::create_table<AuthObject>();
    qx::dao::create_table<AuthServiceMethod>();
    qx::dao::create_table<AuthUserToken>();
    AuthObject * seeUser = new AuthObject();
    seeUser->m_id = "SEE_USER";
    qx::dao::insert(seeUser);
}
