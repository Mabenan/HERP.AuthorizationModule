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
#include <QxHttpServer/QxHttpServer.h>

WebAuthorization::WebAuthorization(QObject *parent) : WebInterface(parent){
	// TODO Auto-generated constructor stub

}

WebAuthorization::~WebAuthorization() {
	// TODO Auto-generated destructor stub
}

QString WebAuthorization::getName() const {
	return "webAuth";
}

QString WebAuthorization::getRoute(ApplicationServerInterface * /*app*/) {
	return "\/api\/(login|logout)";
}

void WebAuthorization::execute(qx::QxHttpRequest  & request, qx::QxHttpResponse & response, ApplicationServerInterface *  /*app*/) {
	QJsonObject jsonRequest;
	QJsonObject jsonResult;
	QJsonParseError parseError{};
	QString user;
	auto *userObject = new AuthUser();
	if (request.url().path() == "/api/logout") {
		QJsonParseError parseError{};
		jsonRequest =
				QJsonDocument::fromJson(request.data(), &parseError).object();
		QString user = jsonRequest["user"].toString();
		QString auth_guid = QString::fromUtf8( request.headers()["auth_guid"]);
		userObject->name = user;
		if (qx::dao::exist(userObject)) {
			qx::dao::fetch_by_id(userObject);
			if (userObject->authGuid == auth_guid) {
				userObject->authGuid = "";
				qx::dao::save(userObject);
				response.data() = QJsonDocument(jsonResult).toJson();
			} else {
				response.status() = 401;
			}
		} else {
			response.status() = 401;
		}
	} else if (request.url().path() == "/api/login") {
		jsonRequest =
				QJsonDocument::fromJson(request.data(), &parseError).object();
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
				response.status() = 401;
			}
		} else {
			response.status() = 401;
		}
		jsonResult["auth_guid"] = userObject->authGuid;
		response.data() = QJsonDocument(jsonResult).toJson();
	} else {
		response.status() = 401;

	}
}
