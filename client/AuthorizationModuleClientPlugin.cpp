
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

    Q_INIT_RESOURCE(herpAuthorizationModule);
}

AuthorizationModuleClientPlugin::~AuthorizationModuleClientPlugin() {
    // TODO Auto-generated destructor stub
}

void AuthorizationModuleClientPlugin::init(ApplicationClientInterface * app) {
this->dashboard = new UserDashboardItem(app, this);
    app->addDashboardItem(this->dashboard);
    QDir tmp(QStandardPaths::locate(QStandardPaths::TempLocation, "", QStandardPaths::LocateDirectory));
    if(QFile::exists(tmp.path() + QDir::separator() + "app.data")){
        QFile file(tmp.path() + QDir::separator() + "app.data");
        file.open(QFile::ReadOnly);
        QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
        UserInformation::user = doc.object().value("user").toString();
        UserInformation::token = doc.object().value("token").toString();
        file.close();
    }

    qx::IxClass * thisClass =qx::QxClassX::getClass("AuthServiceMethod");
    qx::IxDataMemberX * props = thisClass->getDataMemberX();
    for(int i = 0; i < props->size(); i++){
        qDebug() << props->get(i)->getName();
    }

}
void AuthorizationModuleClientPlugin::install(ApplicationClientInterface * app){
}


const QString AuthorizationModuleClientPlugin::getName()
{
    return QStringLiteral("HERP.AuthorizationModule");
}
