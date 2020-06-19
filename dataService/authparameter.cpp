#include "authparameter.h"

#ifdef _APP_CLIENT
#include "QtNetwork"
UserInformation * UserInformation::_instance = 0;

void UserInformation::logout()
{

    QNetworkAccessManager * manager = new QNetworkAccessManager(this);
    QNetworkRequest request;

    QString ip = qx::service::QxConnect::getSingleton()->getIp();
    int port = qx::service::QxConnect::getSingleton()->getPort();
    QUrl url;
    url.setUrl("http://" + ip);
    url.setPort(port);
    url.setPath(QStringLiteral("/api/logout"));
    request.setUrl(url);
     QJsonObject body;
     body.insert("user", QJsonValue(this->user));
     body.insert("auth_guid", QJsonValue(this->token));

     QJsonDocument jsonDoc(body);
     QByteArray bodyData= jsonDoc.toJson();
     request.setHeader(QNetworkRequest::KnownHeaders::ContentTypeHeader, "application/json");
     manager->post(request, bodyData);
   this->user.clear();
   this->token.clear();
   emit logedout();
}

void UserInformation::login(QString user, QString token)
{
    this->user = user;
    this->token = token;
    emit logedin();
}
#endif



