
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
    this->logoutButton = new LogoutButton();
}

AuthorizationModuleClientPlugin::~AuthorizationModuleClientPlugin() {
    // TODO Auto-generated destructor stub
}

void AuthorizationModuleClientPlugin::init(ApplicationClientInterface * app) {
    this->app = app;
    QObject::connect(UserInformation::instance(), &UserInformation::logedin, this, &AuthorizationModuleClientPlugin::onlogin);
    QObject::connect(UserInformation::instance(), &UserInformation::logedout, this, &AuthorizationModuleClientPlugin::onlogout);
this->dashboard = new UserDashboardItem(app, this);
    app->addDashboardItem(this->dashboard);
    QDir tmp(QStandardPaths::locate(QStandardPaths::TempLocation, "", QStandardPaths::LocateDirectory));
    if(QFile::exists(tmp.path() + QDir::separator() + "app.data")){
        QFile file(tmp.path() + QDir::separator() + "app.data");
        file.open(QFile::ReadOnly);
        QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
        QString user = doc.object().value("user").toString();
        QString token = doc.object().value("token").toString();
        UserInformation::instance()->login(user, token);
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

void AuthorizationModuleClientPlugin::onlogin()
{
    this->app->addSideMenuButton(this->logoutButton);
}

void AuthorizationModuleClientPlugin::onlogout()
{
    QDir tmp(QStandardPaths::locate(QStandardPaths::TempLocation, "", QStandardPaths::LocateDirectory));
    if(QFile::exists(tmp.path() + QDir::separator() + "app.data")){
        QFile file(tmp.path() + QDir::separator() + "app.data");
        file.remove();
    }
    this->app->removeSideMenuButton(this->logoutButton);

}
