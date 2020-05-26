/*
 * AuthObject.cpp
 *
 *  Created on: 25.02.2020
 *      Author: daniel
 */

#include <QxOrm_Impl.h>
#include <data/AuthGroup.h>
#include <data/AuthObject.h>
HERP_REGISTER_CPP_HERP_AUTHORIZATION_MODULE(AuthObject)

namespace qx {
template <> void register_class(QxClass<AuthObject> &t) {
  t.setName(QStringLiteral("t_auth_object"));
  t.id(&AuthObject::m_id, QStringLiteral("auth_object_id"));
  t.relationManyToMany(
      &AuthObject::m_auth_groups, QStringLiteral("list_auth_groups"),
      QStringLiteral("t_auth_granted"), QStringLiteral("auth_object_id"),
      QStringLiteral("auth_group_id"));
}
} // namespace qx

AuthObject::AuthObject() { this->m_id = QLatin1String(); }

AuthObject::~AuthObject() = default;
