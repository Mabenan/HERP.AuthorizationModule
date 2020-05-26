
#include "userdashboarditem.h"
/*
 * AuthorizationModulePlugin.cpp
 *
 *  Created on: 29.02.2020
 *      Author: doene
 */

#include <AuthorizationModuleClientPlugin.h>
#include <data/AuthGroup.h>
#include <data/AuthObject.h>
#include <data/AuthUser.h>
#include <dataService/AuthUserService.h>
#include <QMessageBox>
AuthorizationModuleClientPlugin::AuthorizationModuleClientPlugin(QObject *parent) : ApplicationClientPluginInterface(parent) {
    // TODO Auto-generated constructor stub

}

AuthorizationModuleClientPlugin::~AuthorizationModuleClientPlugin() {
    // TODO Auto-generated destructor stub
}

void AuthorizationModuleClientPlugin::init(ApplicationClientInterface * app) {

    app->addDashboardItem(new UserDashboardItem());

}
void AuthorizationModuleClientPlugin::install(ApplicationClientInterface * app){
}
