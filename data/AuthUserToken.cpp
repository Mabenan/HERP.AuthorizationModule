#include "AuthUserToken.h"
#include <QxOrm_Impl.h>
#include "AuthUser.h"

HERP_REGISTER_CPP_HERP_AUTHORIZATION_MODULE(AuthUserToken)
QX_PERSISTABLE_CPP(AuthUserToken)

namespace qx {
template <> void register_class(QxClass<AuthUserToken> &t) {
  t.setName(QStringLiteral("t_auth_user_token"));
  t.id(&AuthUserToken::m_key, AuthUserToken::str_composite_key());
  t.fctStatic_2<QVariant, QVariant, QString>(&AuthUserToken::makeAccisable, "makeAccisable");
  t.relationManyToOne(&AuthUserToken::auth_user, "auth_user_name");
}
} // namespace qx

AuthUserToken::AuthUserToken(QObject * parent) { }

AuthUserToken::~AuthUserToken() = default;
