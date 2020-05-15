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

void AuthorizationModuleClientPlugin::init(ApplicationClientInterface *app) {

  AuthUserService service ;
  service.fetch_all();

  list_auth_user output = (service.isValidWithOutput() ? service.getOutputParameter()->list_of_users : list_auth_user());
  qDebug() << QString(QString("qxClient - get all users") + QString("database contains '") + QString::number(output.size()) + QString("' user(s)."));

}
void AuthorizationModuleClientPlugin::install(ApplicationClientInterface * app){
}
