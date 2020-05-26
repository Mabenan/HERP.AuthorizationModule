/*
 * AuthUser.cpp
 *
 *  Created on: 25.02.2020
 *      Author: daniel
 */

#include <QxOrm_Impl.h>
#include <data/AuthUser.h>

HERP_REGISTER_CPP_HERP_AUTHORIZATION_MODULE(AuthUser)

namespace qx {
template <> void register_class(QxClass<AuthUser> &t) {
  t.setName(QStringLiteral("t_auth_user"));
  t.id(&AuthUser::name, QStringLiteral("auth_user_name"));
  t.data(&AuthUser::pass, QStringLiteral("pass"));
  t.data(&AuthUser::authGuid, QStringLiteral("auth_guid"));
  t.relationManyToMany(
      &AuthUser::m_auth_groups, QStringLiteral("list_auth_group"),
      QStringLiteral("t_auth_user_group"), QStringLiteral("auth_user_name"),
      QStringLiteral("auth_group_id"));
}
} // namespace qx
