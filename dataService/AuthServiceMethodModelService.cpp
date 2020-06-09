#include "AuthServiceMethodModelService.h"

AuthServiceMethodModel::AuthServiceMethodModel(QObject *parent) : auth_service_method_model_base_class(parent)
{

}

AuthServiceMethodModel::AuthServiceMethodModel(qx::IxModel *other, QObject *parent) : auth_service_method_model_base_class(other, parent)
{

}

AuthServiceMethodModel::~AuthServiceMethodModel()
{

}

QObject *AuthServiceMethodModel::auth_object(int row, bool bLoadFromDatabase, const QString &sAppendRelations)
{
    QString sRelation = "auth_object_id";
    qx::IxModel * pChild = (bLoadFromDatabase ? NULL : this->getChild(row, sRelation));
    if (pChild) { return static_cast<QObject *>(pChild); }

    if ((row < 0) || (row >= this->m_model.count())) { qDebug() << this->m_model.count(); return NULL; }
    auth_service_method_model_base_class::type_ptr ptr = this->m_model.getByIndex(row);
    if (! ptr) { qAssert(false); return NULL; }
     auth_object_ptr value = ptr->m_auth_object;
#ifdef _APP_CLIENT
    if (bLoadFromDatabase)
    {
       if (! sAppendRelations.isEmpty() && ! sAppendRelations.startsWith("->") && ! sAppendRelations.startsWith(">>")) { sRelation += "->" + sAppendRelations; }
       else if (! sAppendRelations.isEmpty()) { sRelation += sAppendRelations; }
       auth_service_method_ptr tmp =
               auth_service_method_ptr(new AuthServiceMethod());
       tmp->m_key = QPair<QString, QString>(ptr->service_name(), ptr->function_name());
       AuthServiceMethodService service;
       this->m_lastError = service.fetchById(tmp, QStringList(), QStringList({"*"}));
       if (this->m_lastError.isValid()) { qDebug() << this->m_lastError.text(); return NULL; }
       value = tmp->m_auth_object;
       ptr->m_auth_object = value;
    }
#endif

    qx::QxModel<AuthObject> * pNewChild = NULL;
    pChild = qx::model_view::create_nested_model_with_type(this, QModelIndex(), value, pNewChild);
    if (pChild) { this->insertChild(row, sRelation, pChild); }
    return static_cast<QObject *>(pChild);

}

void AuthServiceMethodModel::syncNestedModel(int row, const QStringList &relation)
{
    Q_UNUSED(relation);
    qx::IxModel * pNestedModel = NULL;
    if ((row < 0) || (row >= this->m_model.count())) { return; }
    auth_service_method_model_base_class::type_ptr ptr = this->m_model.getByIndex(row);
    if (! ptr) { return; }

    pNestedModel = this->getChild(row, "auth_object_id");
    if (pNestedModel)
    {
       this->syncNestedModelRecursive(pNestedModel, relation);
       auth_object_ptr value;
       qx::model_view::sync_nested_model(pNestedModel, value);
       ptr->m_auth_object = value;
    }

}

void AuthServiceMethodModel::syncAllNestedModel(const QStringList &relation)
{
    if (this->m_lstChild.count() <= 0) { return; }
    for (long l = 0; l < this->m_model.count(); l++)
    { this->syncNestedModel(static_cast<int>(l), relation); }

}
