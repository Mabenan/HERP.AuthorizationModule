#ifndef AUTHPARAMETER_H
#define AUTHPARAMETER_H

#include <HERP.AuthorizationModule.Precompiled.h>

#ifdef _APP_CLIENT
class UserInformation {
public:
  static QString user;
  static QString token;
};
#endif
template <typename O, typename L>
class HERP_AUTHORIZATION_MODULE_DLL_EXPORT AuthParameter
    : public QxInputParameterBase<O, L> {
public:
  AuthParameter(): QxInputParameterBase<O, L> () {
#ifdef _APP_CLIENT
    login = UserInformation::user;
    token = UserInformation::token;

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
