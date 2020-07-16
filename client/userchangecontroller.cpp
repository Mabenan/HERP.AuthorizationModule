#include "userchangecontroller.h"

#include <AuthServiceMethodModelService.h>
#include <AuthUserService.h>
#include <authparameter.h>
UserChangeController::UserChangeController(QObject *parent) : QObject(parent)
{
    this->m_listModel = new AuthServiceMethodModel();
    this->m_listModel->qxFetchAll_();

}

qx::IxModel *UserChangeController::userListModel() { return this->m_listModel; }
