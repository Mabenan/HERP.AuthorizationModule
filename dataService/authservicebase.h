#ifndef AUTHSERVICEBASE_H
#define AUTHSERVICEBASE_H

#include "authparameter.h"
#include <HERP.AuthorizationModule.Precompiled.h>

#ifndef _APP_CLIENT
#include <ApplicationServerInterface.h>

#include <data/AuthServiceMethod.h>

#include <QxRegister/QxClass.h>
#endif

class ApplicationServerInterfaceProvider {

#ifndef _APP_CLIENT
private:
  static ApplicationServerInterface *app;

public:
  static void SetApp(ApplicationServerInterface *sApp) {
    ApplicationServerInterfaceProvider::app = sApp;
  }
  static ApplicationServerInterface *GetApp() {
    return ApplicationServerInterfaceProvider::app;
  }
#endif
};

template <class INPUT, class OUTPUT, class OBJECT, typename LIST>
class HERP_AUTHORIZATION_MODULE_DLL_EXPORT AuthServiceBase
    : public QxServiceBase<INPUT, OUTPUT, OBJECT, LIST> {
private:

public:
  AuthServiceBase(const QString &sServiceName)
      : QxServiceBase<INPUT, OUTPUT, OBJECT, LIST>(sServiceName) {

#ifndef _APP_CLIENT
    qx::IxClass * thisClass =qx::QxClassX::getClass(sServiceName);
    qx::IxFunctionX * functions = thisClass->getFctMemberX();
    for(qx::IxFunctionX::type_pair_key_value function : *functions){
        AuthServiceMethod *serviceMethodObject = new AuthServiceMethod();
       serviceMethodObject->m_key.first = sServiceName;
        serviceMethodObject->m_key.second = function.first;
        if(!qx::dao::exist(serviceMethodObject)){
            qx::dao::insert(serviceMethodObject);
        }
    }
#endif

  }
  virtual ~AuthServiceBase() { ; }
  typedef std::shared_ptr<INPUT> parameter_ptr;

#ifndef _APP_CLIENT
  virtual void onBeforeProcess() {
    // Here you can implement your own authentication control (checking
    // login/password for example) You can get input authentication parameters
    // like this :
    parameter_ptr pParams = this->getInputParameter();
    QMap<QString, QVariant> params;
    QString serviceName = this->getServiceName();
    QString serviceMethod = this->getServiceMethodName();
    AuthServiceMethod *serviceMethodObject = new AuthServiceMethod();
    serviceMethodObject->m_key.first  = serviceName;
    serviceMethodObject->m_key.second = serviceMethod;
    qx::dao::fetch_by_id_with_all_relation(serviceMethodObject);
    if (serviceMethodObject->m_auth_object) {
      params.insert(QStringLiteral("auth_guid"), QVariant(pParams->token));
      if (!ApplicationServerInterfaceProvider::GetApp()->isUserAuthorized(
              pParams->login, serviceMethodObject->m_auth_object->m_id, params)) {
        throw qx::exception("Authentication error !");
      }
    }
  }
#endif
};
#define REGISTER_AUTH_SERVICE_BASE(type1, type2, type3, type4)                 \
  namespace qx {                                                               \
  template <>                                                                  \
  void                                                                         \
  register_class(QxClass<AuthServiceBase<type1, type2, type3, type4>> &t) {}   \
  }

QX_REGISTER_CLASS_NAME_TEMPLATE_4(AuthServiceBase)

#endif // AUTHSERVICE_H
