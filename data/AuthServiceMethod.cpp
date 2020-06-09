#include "AuthServiceMethod.h"
#include <QxOrm_Impl.h>

HERP_REGISTER_CPP_HERP_AUTHORIZATION_MODULE(AuthServiceMethod)

namespace qx {
template <> void register_class(QxClass<AuthServiceMethod> &t) {
  t.setName(QStringLiteral("t_auth_service_name"));
  t.id(&AuthServiceMethod::m_key, AuthServiceMethod::str_composite_key());
  t.relationManyToOne(&AuthServiceMethod::m_auth_object, QStringLiteral("auth_object_id"));
  t.fctStatic_2<QVariant, QVariant, QString>(&AuthServiceMethod::makeAccisable, "makeAccisable");
}
} // namespace qx

AuthServiceMethod::AuthServiceMethod(QObject * parent) : QObject(parent) { }

AuthServiceMethod::~AuthServiceMethod() = default;
