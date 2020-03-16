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
#include <data/AuthUser.h>
#include <command/AuthProvider.h>
#include <webServices/WebAuthorization.h>
#include <entity/UserEntitySet.h>
#include <entity/CurrentUserFunction.h>

AuthorizationModulePlugin::AuthorizationModulePlugin(QObject *parent) : ApplicationServerPluginInterface(parent) {
	// TODO Auto-generated constructor stub

}

AuthorizationModulePlugin::~AuthorizationModulePlugin() {
	// TODO Auto-generated destructor stub
}

void AuthorizationModulePlugin::init(ApplicationServerInterface *app) {

	app->registerCommand(new ListAuthGroupCommand(this));
	app->registerAuthProvider(new AuthProvider(this));
	app->registerWebInterface(new WebAuthorization(this));
	ODataEntityContainer * routeEntityContainer = new ODataEntityContainer();
	ODataSchema * schema1 = new ODataSchema("Authorization", routeEntityContainer);

	routeEntityContainer->entitySets.insert("UserSet", new UserEntitySet());
	routeEntityContainer->functions.insert("CurrentUser", new CurrentUserFunction());
	app->addValue("ODATA_SCHEMA_MAP", schema1);

}
void AuthorizationModulePlugin::install(ApplicationServerInterface * app){
	qx::dao::create_table<AuthGroup>();
	qx::dao::create_table<AuthUser>();
	qx::dao::create_table<AuthObject>();
}
