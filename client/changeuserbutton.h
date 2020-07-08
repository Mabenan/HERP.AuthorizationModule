#ifndef CHANGEUSERBUTTON_H
#define CHANGEUSERBUTTON_H

#include <QObject>
#include <ApplicationClientInterface.h>
#include "Button.h"
#include <MainView.h>
#include "userchangeview.h"
class ChangeUserButton : public Button
{
private:
    ApplicationClientInterface * app;
public:
    ChangeUserButton(ApplicationClientInterface * app);
public:
    void clicked() override{
        app->showView(new UserChangeView());
    }
    const QString name() override{
        return QStringLiteral("Change User");
    }
};

#endif // CHANGEUSERBUTTON_H
