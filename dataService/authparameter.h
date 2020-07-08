#ifndef AUTHPARAMETER_H
#define AUTHPARAMETER_H

#include <HERP.AuthorizationModule.Precompiled.h>

#ifdef _APP_CLIENT
class HERP_AUTHORIZATION_MODULE_DLL_EXPORT UserInformation : public QObject
{
    Q_OBJECT
private:
    static UserInformation * _instance;
public:
    static UserInformation *instance() {
      if (!_instance)
        _instance = new UserInformation();
      return _instance;
    }
  QString user;
  QString token;
  void  logout();
  void login(QString user, QString token);
Q_SIGNALS:
  void logedout();
  void logedin();

};
#endif
template <typename O, typename L>
class HERP_AUTHORIZATION_MODULE_DLL_EXPORT AuthParameter
    : public QxInputParameterBase<O, L> {
public:
    typedef QxInputParameterBase<O, L> baseClass;
  AuthParameter(): QxInputParameterBase<O, L> () {
#ifdef _APP_CLIENT
    login = UserInformation::instance()->user;
    token = UserInformation::instance()->token;

#endif

  }
  QString login;
  QString token;
};
#define REGISTER_AUTH(type1, type2)\
namespace qx {\
template<> void register_class(QxClass<AuthParameter<type1,type2>> &t) {\
    t.data(&AuthParameter<type1,type2>::login, QStringLiteral("login"));\
    t.data(&AuthParameter<type1,type2>::token, QStringLiteral("token"));\
}\
}\
REGISTER_INPUT_PARAMETER_BASE(type1,type2)
QX_REGISTER_CLASS_NAME_TEMPLATE_2(AuthParameter)
#endif // AUTHPARAMETER_H
