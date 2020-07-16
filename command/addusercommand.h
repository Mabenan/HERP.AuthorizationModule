#ifndef ADDUSERCOMMAND_H
#define ADDUSERCOMMAND_H


#include <QObject>
#include <CommandInterface.h>
class AddUserCommand : public CommandInterface
{
    Q_OBJECT
public:
    AddUserCommand(QObject * parent = nullptr);
    ~AddUserCommand() override;
    void execute(ApplicationServerInterface *app, QStringList args) override;
    QString getName() const override;
};

#endif // ADDUSERCOMMAND_H
