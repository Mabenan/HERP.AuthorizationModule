#include "addusercommand.h"

#include <data/AuthUser.h>

AddUserCommand::AddUserCommand(QObject *parent) : CommandInterface(parent)
{

}

AddUserCommand::~AddUserCommand()
{

}

void AddUserCommand::execute(ApplicationServerInterface *app, QStringList args)
{
    if(args.length() < 2){
        qWarning() << QStringLiteral("Please enter the Command the Following addUser {username} {pass}");
    }
    qInfo() << QStringLiteral("Adding User ") + args[0];
    AuthUser * user = new AuthUser();
    QString passwordHash = QString::fromUtf8(
        QCryptographicHash::hash(args[1].toUtf8(), QCryptographicHash::Sha256)
            .toHex());
    user->name = args[0];
    user->pass = passwordHash;
    QSqlError error = qx::dao::insert(user);
    if(error.type() != error.NoError){
        qCritical() << error.text();
    }
    qInfo() << QStringLiteral("User Created");
}

QString AddUserCommand::getName() const
{
    return QStringLiteral("addUser");
}
