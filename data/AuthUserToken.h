#ifndef AUTHUSERTOKEN_H
#define AUTHUSERTOKEN_H


#include <QString>
#include <AuthGroup.h>

class AuthUser;
class HERP_AUTHORIZATION_MODULE_DLL_EXPORT AuthUserToken : public qx::IxPersistable{

    Q_PROPERTY(QString username READ username)
    Q_PROPERTY(QString authGuid READ authGuid)
    QX_PERSISTABLE_HPP(AuthUserToken)
public:
    using auth_user_ptr = std::shared_ptr<AuthUser>;
    typedef QPair<QString, QString> type_composite_key;
    static QString str_composite_key() { return "auth_user_name|authGuid"; }
    type_composite_key m_key;
    auth_user_ptr auth_user;

    Q_INVOKABLE QString username(){
        return m_key.first;
    }
    Q_INVOKABLE QString authGuid(){
        return m_key.second;
    }
public:
    AuthUserToken(QObject * parent = nullptr);
    virtual ~AuthUserToken();

    static QVariant makeAccisable(QVariant input, QString column){
        if(column == str_composite_key()){
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
QX_REGISTER_PRIMARY_KEY(AuthUserToken,  AuthUserToken::type_composite_key, m_key);
HERP_REGISTER_HPP_HERP_AUTHORIZATION_MODULE(AuthUserToken, qx::trait::no_base_class_defined, 0);

using auth_user_token_ptr = std::shared_ptr<AuthUserToken>;
using list_auth_user_token = qx::QxCollection<AuthUserToken::type_composite_key, auth_user_token_ptr>;
typedef std::shared_ptr<list_auth_user_token> list_auth_user_token_ptr;
typedef qx::QxCollection<AuthUserToken::type_composite_key, auth_user_token_ptr> map_auth_user_token;

#endif // AUTHUSERTOKEN_H
