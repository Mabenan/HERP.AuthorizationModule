#ifndef USERDASHBOARDITEM_H
#define USERDASHBOARDITEM_H

#include <DashboardItem.h>
#include <QObject>
#include <ApplicationClientInterface.h>
#include <HERP.AuthorizationModule.Precompiled.h>
#include <QtNetwork>
class UserDashboardItem : public DashboardItem
{
    Q_OBJECT
    Q_PROPERTY(qx::IxModel * userListModel READ userListModel)
private:
    QString username;
    bool saveLogin;
    ApplicationClientInterface * app;
    QNetworkAccessManager *manager;
    qx::IxModel * m_listModel;
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
