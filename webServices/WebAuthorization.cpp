/*
 * WebAuthorization.cpp
 *
 *  Created on: 13.03.2020
 *      Author: drichte
 */

#include <QJsonParseError>
#include <QUuid>
#include <QxHttpServer/QxHttpServer.h>
#include <data/AuthUser.h>
#include <webServices/WebAuthorization.h>

WebAuthorization::WebAuthorization(QObject *parent) : WebInterface(parent) {
  // TODO Auto-generated constructor stub
}

WebAuthorization::~WebAuthorization() {
  // TODO Auto-generated destructor stub
}

QString WebAuthorization::getName() const { return QStringLiteral("webAuth"); }

QString WebAuthorization::getRoute(ApplicationServerInterface * /*app*/) {
  return QStringLiteral("/api/(login|logout)");
}

void WebAuthorization::execute(qx::QxHttpRequest &request,
                               qx::QxHttpResponse &response,
                               ApplicationServerInterface */*app*/) {
  QJsonObject jsonRequest;
  QJsonObject jsonResult;
  QJsonParseError parseError{};
  QString user;
  auto *userObject = new AuthUser();
  if (request.url().path() == QLatin1String("/api/logout")) {
    QJsonParseError parseError{};
    jsonRequest = QJsonDocument::fromJson(request.data(), &parseError).object();
    QString user = jsonRequest.value(QStringLiteral("user")).toString();
    QString auth_guid =
         jsonRequest.value(QStringLiteral("auth_guid").toLatin1()).toString();
    userObject->name = user;
    if (qx::dao::exist(userObject)) {
      qx::dao::fetch_by_id_with_all_relation(userObject);
      if (userObject->m_auth_user_tokens.contains(QPair<QString,QString>(user, auth_guid)) ) {
        qx::dao::delete_by_id(userObject->m_auth_user_tokens.getByKey(QPair<QString,QString>(user, auth_guid)));
        userObject->m_auth_user_tokens.removeByKey(QPair<QString,QString>(user, auth_guid));
        qx::dao::save_with_all_relation(userObject);
        response.data() = QJsonDocument(jsonResult).toJson();
      } else {
        response.status() = 401;
      }
    } else {
      response.status() = 401;
    }
  } else if (request.url().path() == QLatin1String("/api/login")) {
    QByteArray data = request.data();
    jsonRequest = QJsonDocument::fromJson(data, &parseError).object();
    if(parseError.error){
        qDebug() << parseError.errorString();
    }
    user = jsonRequest.value(QLatin1String("user")).toString();
    QString password = jsonRequest.value(QLatin1String("password")).toString();
    QString passwordHash = QString::fromUtf8(
        QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256)
            .toHex());
    userObject->name = user;
    auth_user_token_ptr token = nullptr;
    if (qx::dao::exist(userObject)) {
      qx::dao::fetch_by_id(userObject);
      if (userObject->pass == passwordHash) {
        token = auth_user_token_ptr(new AuthUserToken());
        token->m_key = QPair<QString, QString>(user, QUuid::createUuid().toString());
        userObject->m_auth_user_tokens.insert(token->m_key, token);
        token->auth_user = auth_user_ptr(userObject);
        qx::dao::save(token);
        qx::dao::save_with_all_relation(userObject);
      } else {
        qDebug() << passwordHash;
        response.status() = 401;
      }
    } else {
      response.status() = 401;
    }
    jsonResult.insert(QLatin1String("auth_guid"), token->authGuid());
    response.data() = QJsonDocument(jsonResult).toJson();
  } else {
    response.status() = 401;
  }
}
