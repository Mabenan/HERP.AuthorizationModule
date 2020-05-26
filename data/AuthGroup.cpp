/*
 * AuthGroup.cpp
 *
 *  Created on: 25.02.2020
 *      Author: daniel
 */

#include <QxOrm_Impl.h>
#include <data/AuthGroup.h>
#include <data/AuthUser.h>

HERP_REGISTER_CPP_HERP_AUTHORIZATION_MODULE(AuthGroup)

namespace qx {
template <> void register_class(QxClass<AuthGroup> &t) {
  t.setName(QStringLiteral("t_auth_group"));
  t.id(&AuthGroup::m_name, QStringLiteral("auth_group_id"));
  t.relationManyToMany(
      &AuthGroup::m_auth_users, QStringLiteral("list_auth_user"),
      QStringLiteral("t_auth_user_group"), QStringLiteral("auth_group_id"),
      QStringLiteral("auth_user_id"));
  t.relationManyToMany(
      &AuthGroup::m_auths_granted, QStringLiteral("list_auth_granted"),
      QStringLiteral("t_auth_granted"), QStringLiteral("auth_group_id"),
      QStringLiteral("auth_object_id"));
}
} // namespace qx

AuthGroup::AuthGroup() { this->m_name = QLatin1String(); }

AuthGroup::~AuthGroup() {
  // TODO Auto-generated destructor stub
}
