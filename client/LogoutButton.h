#ifndef LOGOUTBUTTON_H
#define LOGOUTBUTTON_H

#include "Button.h"

#include <authparameter.h>
class LogoutButton : public Button
{
    Q_OBJECT
private:
public:
    LogoutButton(QObject * parent = nullptr) : Button(parent){

    }

    // Button interface
public:
    void clicked() override{
        UserInformation::instance()->logout();
    }
    const QString name() override{
        return QStringLiteral("Logout");
    }
};
#endif // LOGOUTBUTTON_H
