/*
 * AuthObject.h
 *
 *  Created on: 25.02.2020
 *      Author: daniel
 */

#ifndef REPS_HERP_AUTHORIZATIONMODULE_DATA_AUTHOBJECT_H_
#define REPS_HERP_AUTHORIZATIONMODULE_DATA_AUTHOBJECT_H_

#include <QString>
#include <QxOrm.h>
class AuthGroup;

class HERP_AUTHORIZATION_MODULE_DLL_EXPORT AuthObject : public qx::IxPersistable{
    QX_PERSISTABLE_HPP(AuthObject)
public:
    using auth_group_ptr = std::shared_ptr<AuthGroup>;
    using list_auth_group = std::vector<auth_group_ptr>;
    QString m_id;
    list_auth_group m_auth_groups;
public:
    AuthObject();
    virtual ~AuthObject();
};
QX_REGISTER_PRIMARY_KEY(AuthObject, QString, m_id);
HERP_REGISTER_HPP_HERP_AUTHORIZATION_MODULE(AuthObject, qx::trait::no_base_class_defined, 0);


using auth_object_ptr = std::shared_ptr<AuthObject>;

using list_auth_object = std::vector<auth_object_ptr>;
typedef qx::QxCollection<long, auth_object_ptr> map_auth_object;
#endif /* REPS_HERP_AUTHORIZATIONMODULE_DATA_AUTHOBJECT_H_ */
