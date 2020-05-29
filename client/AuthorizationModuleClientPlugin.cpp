
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

}

AuthorizationModuleClientPlugin::~AuthorizationModuleClientPlugin() {
    // TODO Auto-generated destructor stub
}

void AuthorizationModuleClientPlugin::init(ApplicationClientInterface * app) {
this->dashboard = new UserDashboardItem(app, this);
    app->addDashboardItem(this->dashboard);

}
void AuthorizationModuleClientPlugin::install(ApplicationClientInterface * app){
}


const QString AuthorizationModuleClientPlugin::getName()
{
    return QStringLiteral("HERP.AuthorizationModule");
}
