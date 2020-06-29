#ifndef AUTHSERVICEMETHODMODELSERVICE_H
#define AUTHSERVICEMETHODMODELSERVICE_H

#include <dataService/AuthServiceMethodService.h>
#include <qxmodelbase.h>
typedef QxModelServiceBase<AuthServiceMethod, AuthServiceMethodService, AuthServiceMethod::type_composite_key> auth_service_method_model_base_class;
class HERP_AUTHORIZATION_MODULE_DLL_EXPORT AuthServiceMethodModel : public auth_service_method_model_base_class
{
    Q_OBJECT
public:
    AuthServiceMethodModel(QObject * parent = nullptr);
    AuthServiceMethodModel(qx::IxModel * other, QObject * parent);
    virtual ~AuthServiceMethodModel();
    Q_INVOKABLE QObject *auth_object(int row, bool bLoadFromDatabase = false, const QString & sAppendRelations = QString());
protected:

   virtual void syncNestedModel(int row, const QStringList & relation);
   virtual void syncAllNestedModel(const QStringList & relation);
};
#endif // AUTHSERVICEMETHODMODELSERVICE_H
