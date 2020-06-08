/*
 * ListAuthGroupCommand.h
 *
 *  Created on: 29.02.2020
 *      Author: doene
 */

#ifndef REPS_HERP_AUTHORIZATIONMODULE_COMMAND_LISTAUTHGROUPCOMMAND_H_
#define REPS_HERP_AUTHORIZATIONMODULE_COMMAND_LISTAUTHGROUPCOMMAND_H_

#include <CommandInterface.h>

class ListAuthGroupCommand: public CommandInterface {
    Q_OBJECT
public:
    ListAuthGroupCommand(QObject * parent = nullptr);
    ~ListAuthGroupCommand() override;
    void execute(ApplicationServerInterface *app, QStringList args) override;
    QString getName() const override;
};

#endif /* REPS_HERP_AUTHORIZATIONMODULE_COMMAND_LISTAUTHGROUPCOMMAND_H_ */
