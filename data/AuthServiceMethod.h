#ifndef AUTHSERVICEMETHOD_H
#define AUTHSERVICEMETHOD_H

#include <HERP.AuthorizationModule.Precompiled.h>
#include <QString>
#include <QxOrm.h>
#include <data/AuthObject.h>

class HERP_AUTHORIZATION_MODULE_DLL_EXPORT AuthServiceMethod
{

    Q_PROPERTY(QString service_name READ service_name)
    Q_PROPERTY(QString function_name READ function_name)
public:
    typedef QPair<QString, QString> type_composite_key;
    static QString str_composite_key() { return "service_name|function_name"; }
    type_composite_key m_key;
    auth_object_ptr m_auth_object;

    QString service_name(){
        return m_key.first;
    }
    QString function_name(){
        return m_key.second;
    }
public:
    AuthServiceMethod();
    virtual ~AuthServiceMethod();

    static QVariant makeAccisable(QVariant input, QString column){
        if(column == "service_name|function_name"){
            type_composite_key value;
            qx::cvt::from_variant<type_composite_key>(input, value);
            QList<QString> values;
            values.append(value.first);
            values.append(value.second);
            return QVariant::fromValue(values);
        }
        return QVariant();
    }
};
QX_REGISTER_PRIMARY_KEY(AuthServiceMethod, AuthServiceMethod::type_composite_key, m_key);
HERP_REGISTER_HPP_HERP_AUTHORIZATION_MODULE(AuthServiceMethod, qx::trait::no_base_class_defined, 0);


using auth_service_method_ptr = std::shared_ptr<AuthServiceMethod>;
using list_auth_service_method = qx::QxCollection<AuthServiceMethod::type_composite_key, auth_service_method_ptr>;
typedef std::shared_ptr<list_auth_service_method> list_auth_service_method_ptr;
typedef qx::QxCollection<AuthServiceMethod::type_composite_key, auth_service_method_ptr> map_auth_service_method;

#endif // AUTHSERVICEMETHOD_H
