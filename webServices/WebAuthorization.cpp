/*
 * WebAuthorization.cpp
 *
 *  Created on: 13.03.2020
 *      Author: drichte
 */

#include <webServices/WebAuthorization.h>
#include <QUuid>
#include <QJsonParseError>
#include <data/AuthUser.h>

WebAuthorization::WebAuthorization(QObject *parent) : WebInterface(parent){
	// TODO Auto-generated constructor stub

}

WebAuthorization::~WebAuthorization() {
	// TODO Auto-generated destructor stub
}

QString WebAuthorization::getName() const {
	return "webAuth";
}

QString WebAuthorization::getRoute(ApplicationServerInterface *app) {
	return "\/api\/(login|logout)";
}

QHttpServerResponse WebAuthorization::execute(const QHttpServerRequest *request,
		ApplicationServerInterface *app) {
	QJsonObject jsonRequest;
	QJsonObject jsonResult;
	QJsonParseError parseError;
	QString user;
	AuthUser *userObject = new AuthUser();
	if (request->url().path() == "/api/logout") {
		QJsonParseError parseError;
		jsonRequest =
				QJsonDocument::fromJson(request->body(), &parseError).object();
		QString user = jsonRequest["user"].toString();
		QString auth_guid = request->headers()["auth_guid"].toString();
		userObject->name = user;
		if (qx::dao::exist(userObject)) {
			qx::dao::fetch_by_id(userObject);
			if (userObject->authGuid == auth_guid) {
				userObject->authGuid = "";
				qx::dao::save(userObject);
			} else {
				return QHttpServerResponse(
						QHttpServerResponse::StatusCode::Unauthorized);
			}
		} else {
			return QHttpServerResponse(
					QHttpServerResponse::StatusCode::Unauthorized);
		}
		return QHttpServerResponse(QHttpServerResponse::StatusCode::Ok);
	} else if (request->url().path() == "/api/login") {
		jsonRequest =
				QJsonDocument::fromJson(request->body(), &parseError).object();
		user = jsonRequest["user"].toString();
		QString password = jsonRequest["password"].toString();
		QString passwordHash = QString(QCryptographicHash::hash(password.toUtf8(),QCryptographicHash::Sha256).toHex());
		userObject->name = user;
		if (qx::dao::exist(userObject)) {
			qx::dao::fetch_by_id(userObject);
			if (userObject->pass == passwordHash) {
				userObject->authGuid = QUuid::createUuid().toString();
				qx::dao::save(userObject);
			} else {
				return QHttpServerResponse(
						QHttpServerResponse::StatusCode::Unauthorized);
			}
		} else {
			return QHttpServerResponse(
					QHttpServerResponse::StatusCode::Unauthorized);
		}
		jsonResult["auth_guid"] = userObject->authGuid;
		return jsonResult;
	} else {
		return QHttpServerResponse(
				QHttpServerResponse::StatusCode::NotImplemented);

	}
}
