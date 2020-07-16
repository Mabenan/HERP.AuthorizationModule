#ifndef USERCHANGECONTROLLER_H
#define USERCHANGECONTROLLER_H

#include <QObject>
#include <ApplicationClientInterface.h>
#include <HERP.AuthorizationModule.Client.Precompiled.h>

class UserChangeController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qx::IxModel * userListModel READ userListModel)
private:

    qx::IxModel * m_listModel;
public:
    explicit UserChangeController(QObject *parent = nullptr);
    qx::IxModel * userListModel();

signals:

};

#endif // USERCHANGECONTROLLER_H
