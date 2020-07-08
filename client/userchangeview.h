#ifndef USERCHANGEVIEW_H
#define USERCHANGEVIEW_H

#include "userchangecontroller.h"
#include <MainView.h>
#include <QObject>
class UserChangeView : public MainView<UserChangeController> {
  Q_OBJECT
  MAIN_VIEW
public:
  UserChangeView()
      : MainView<UserChangeController>(
            "/herp/authorizationmodule/userlist.qml") {}

  virtual ~UserChangeView() override { ; }
};
#endif // USERCHANGEVIEW_H
