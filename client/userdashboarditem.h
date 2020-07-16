#ifndef USERDASHBOARDITEM_H
#define USERDASHBOARDITEM_H

#include <DashboardItem.h>
#include <QObject>
#include <ApplicationClientInterface.h>
#include <HERP.AuthorizationModule.Client.Precompiled.h>
#include <QtNetwork>
class UserDashboardItem : public DashboardItem
{
    Q_OBJECT
private:
    QString username;
    bool saveLogin;
    ApplicationClientInterface * app;
    QNetworkAccessManager *manager;
public:
    UserDashboardItem(ApplicationClientInterface * app, QObject * parent = nullptr);
    qx::IxModel * userListModel();
    // DashboardItem interface
public:
    const QString source() override;
    void loginFinished(QNetworkReply *reply);
    void onloginStatusChanged();
    Q_INVOKABLE void remove();
    Q_INVOKABLE void login(const QString &username, const QString &password, const bool &saveLogin);
};

#endif // USERDASHBOARDITEM_H
