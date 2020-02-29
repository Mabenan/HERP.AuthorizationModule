/*
 * AuthorizationModulePlugin.cpp
 *
 *  Created on: 29.02.2020
 *      Author: doene
 */

#include <AuthorizationModulePlugin.h>
#include <command/ListAuthGroupCommand.h>
#include <data/AuthGroup.h>

AuthorizationModulePlugin::AuthorizationModulePlugin(QObject *parent) : ApplicationServerPluginInterface(parent) {
	// TODO Auto-generated constructor stub

}

AuthorizationModulePlugin::~AuthorizationModulePlugin() {
	// TODO Auto-generated destructor stub
}

void AuthorizationModulePlugin::init(ApplicationServerInterface *app) {

	app->registerCommand(new ListAuthGroupCommand(this));

}
void AuthorizationModulePlugin::install(ApplicationServerInterface * app){
	qx::dao::create_table<AuthGroup>();
}
