#include "userdashboarditem.h"

UserDashboardItem::UserDashboardItem(QObject * parent): DashboardItem(parent)
{

}


const QString UserDashboardItem::source()
{
    return QStringLiteral("/herp/authorizationmodule/userdashboard.qml");
}
