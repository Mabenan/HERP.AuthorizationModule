#ifndef AUTHSERVICEBASE_H
#define AUTHSERVICEBASE_H

#include <HERP.AuthorizationModule.Precompiled.h>
#include "authparameter.h"

#ifndef _APP_CLIENT
#include <ApplicationServerInterface.h>
#endif

class ApplicationServerInterfaceProvider{


#ifndef _APP_CLIENT
private:
    static ApplicationServerInterface * app ;
public:
    static void SetApp(ApplicationServerInterface * sApp){
        ApplicationServerInterfaceProvider::app = sApp;
    }
    static ApplicationServerInterface *  GetApp(){
        return ApplicationServerInterfaceProvider::app;
    }
#endif
};

template <class INPUT, class OUTPUT, class OBJECT, typename LIST>
class HERP_AUTHORIZATION_MODULE_DLL_EXPORT AuthServiceBase : public QxServiceBase<INPUT, OUTPUT, OBJECT, LIST>
{
private:
    QString authObject;

public:
    AuthServiceBase(const QString & sServiceName, const QString & sAuthObject) : QxServiceBase<INPUT, OUTPUT, OBJECT, LIST>(sServiceName), authObject(sAuthObject) { ; }
    virtual ~AuthServiceBase() { ; }
   typedef std::shared_ptr<INPUT> parameter_ptr;

#ifndef _APP_CLIENT
    virtual void onBeforeProcess()
    {
       // Here you can implement your own authentication control (checking login/password for example)
       // You can get input authentication parameters like this :
       parameter_ptr pParams = this->getInputParameter();
       QMap<QString, QVariant> params;
       params.insert(QStringLiteral("auth_guid"), QVariant(pParams->token));
       if(!ApplicationServerInterfaceProvider::GetApp()->isUserAuthorized(pParams->login, authObject, params)){
throw qx::exception("Authentication error !");
       }
    }
#endif
};
#define REGISTER_AUTH_SERVICE_BASE(type1, type2, type3, type4)\
namespace qx {\
template<> void register_class(QxClass<AuthServiceBase<type1,type2, type3, type4>> &t) {\
}\
}

QX_REGISTER_CLASS_NAME_TEMPLATE_4(AuthServiceBase)

#endif // AUTHSERVICE_H
