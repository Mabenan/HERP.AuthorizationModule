#ifndef USERDASHBOARDITEM_H
#define USERDASHBOARDITEM_H

#include <DashboardItem.h>
#include <QObject>

class UserDashboardItem : public DashboardItem
{
    Q_OBJECT
public:
    UserDashboardItem(QObject * parent = nullptr);

    // DashboardItem interface
public:
    const QString source() override;
};

#endif // USERDASHBOARDITEM_H
