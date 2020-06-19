#include "userdashboarditem.h"
#include <dataService/AuthServiceMethodModelService.h>
#include <dataService/AuthUserService.h>
#include <dataService/authparameter.h>
UserDashboardItem::UserDashboardItem(ApplicationClientInterface *app,
                                     QObject *parent)
    : DashboardItem(parent) {
  this->app = app;
  this->m_listModel = new AuthServiceMethodModel();
  QObject::connect(UserInformation::instance(), &UserInformation::logedin, this,
                   &UserDashboardItem::onloginStatusChanged);
  QObject::connect(UserInformation::instance(), &UserInformation::logedout,
                   this, &UserDashboardItem::onloginStatusChanged);
}

qx::IxModel *UserDashboardItem::userListModel() { return this->m_listModel; }

void UserDashboardItem::onloginStatusChanged() { emit sourceChanged(); }

const QString UserDashboardItem::source() {
  if (UserInformation::instance()->user.isEmpty() ||
      UserInformation::instance()->token.isEmpty()) {
    return QStringLiteral("/herp/authorizationmodule/userdashboard.qml");
  } else {

    this->m_listModel->qxFetchAll_(QStringList({"auth_object_id"}));
    qDebug() << this->m_listModel->getLastError().text();
    qDebug() << this->m_listModel->rowCount();
    return QStringLiteral("/herp/authorizationmodule/userlist.qml");
  }
}

void UserDashboardItem::remove() { this->app->removeDashboardItem(this); }

void UserDashboardItem::login(const QString &username,
                              const QString &password,
                              const bool &saveLogin) {
  this->manager = new QNetworkAccessManager(this);
  connect(manager, &QNetworkAccessManager::finished, this,
          &UserDashboardItem::loginFinished);
  QNetworkRequest request;

  QString ip = qx::service::QxConnect::getSingleton()->getIp();
  int port = qx::service::QxConnect::getSingleton()->getPort();
  QUrl url;
  url.setUrl("http://" + ip);
  url.setPort(port);
  url.setPath(QStringLiteral("/api/login"));
  request.setUrl(url);
  QJsonObject body;
  body.insert("user", QJsonValue(username));
  body.insert("password", QJsonValue(password));

  QJsonDocument jsonDoc(body);
  QByteArray bodyData = jsonDoc.toJson();
  this->username = username;
  this->saveLogin = saveLogin;
  request.setHeader(QNetworkRequest::KnownHeaders::ContentTypeHeader,
                    "application/json");
  this->manager->post(request, bodyData);
}

void UserDashboardItem::loginFinished(QNetworkReply *reply) {
  while (!reply->isFinished()) {
    reply->waitForReadyRead(
        qx::service::QxConnect::getSingleton()->getMaxWait());
  }
  if (reply->error()) {
    qDebug() << reply->error();
    qDebug() << reply->errorString();
  } else {
    QByteArray buffer = reply->readAll();
    qDebug() << QString::fromUtf8(buffer);
    QJsonDocument jsonDoc = QJsonDocument::fromJson(buffer);
    QJsonObject jsonData = jsonDoc.object();
    qDebug() << jsonData.value("user").toString();
    qDebug() << jsonData.value("auth_guid").toString();
    QString token = jsonData.value("auth_guid").toString();
    UserInformation::instance()->login(this->username, token);
    if (this->saveLogin) {
      QDir tmp(QStandardPaths::locate(QStandardPaths::TempLocation, "",
                                      QStandardPaths::LocateDirectory));
      QFile file(tmp.path() + QDir::separator() + "app.data");
      file.open(QFile::OpenModeFlag::ReadWrite);
      file.seek(0);

      QJsonDocument doc;
      QJsonObject userObject;
      userObject.insert("user", UserInformation::instance()->user);
      userObject.insert("token", UserInformation::instance()->token);
      doc.setObject(userObject);
      file.write(doc.toJson());
      file.close();
    }
  }
}
