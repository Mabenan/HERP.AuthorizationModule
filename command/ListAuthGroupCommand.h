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
	virtual ~ListAuthGroupCommand();
	virtual void execute(ApplicationServerInterface *app);
	virtual QString getName() const;
};

#endif /* REPS_HERP_AUTHORIZATIONMODULE_COMMAND_LISTAUTHGROUPCOMMAND_H_ */
