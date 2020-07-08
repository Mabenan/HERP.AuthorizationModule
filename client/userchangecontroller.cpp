#include "userchangecontroller.h"

#include <dataService/AuthServiceMethodModelService.h>
#include <dataService/AuthUserService.h>
#include <dataService/authparameter.h>
UserChangeController::UserChangeController(QObject *parent) : QObject(parent)
{
    this->m_listModel = new AuthServiceMethodModel();
    this->m_listModel->qxFetchAll_();

}

qx::IxModel *UserChangeController::userListModel() { return this->m_listModel; }
