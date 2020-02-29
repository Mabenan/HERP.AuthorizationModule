/*
 * ListAuthGroupCommand.cpp
 *
 *  Created on: 29.02.2020
 *      Author: doene
 */

#include <command/ListAuthGroupCommand.h>
#include <QxOrm.h>
#include <data/AuthGroup.h>
ListAuthGroupCommand::ListAuthGroupCommand(QObject * parent) : CommandInterface(parent) {
	// TODO Auto-generated constructor stub

}

ListAuthGroupCommand::~ListAuthGroupCommand() {
	// TODO Auto-generated destructor stub
}

void ListAuthGroupCommand::execute(ApplicationServerInterface *app) {
	map_auth_group authGroups;
	qx::dao::fetch_all(authGroups);
	for(map_auth_group::type_pair_key_value authGroup : authGroups){
		qDebug() << authGroup.second->m_name;
	}
}

QString ListAuthGroupCommand::getName() const {
	return "listauthgroup";
}
