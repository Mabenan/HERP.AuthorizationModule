import QtQuick 2.13
import QtQuick.Controls 2.13
import Qt.labs.qmlmodels 1.0
import com.applicationclient 1.0 as AppClient

//ListView {
//    id: userList

//    property variant myDashboard;
//    function setDashboard(dashboard){
//        myDashboard = dashboard;
//        console.log(myDashboard.source);
//    }

//    model: myDashboard.userListModel
//    width: parent.width
//    height: childrenRect.height
//    delegate:
//        Row {
//        spacing: 10

//        Text {
//            text: index
//            font.bold: true
//            anchors.verticalCenter: parent.verticalCenter
//        }
//        Text {
//            text: AppClient.App.makeAccisable("service_name|function_name", index, userList.model)[0]
//            font.bold: true
//            anchors.verticalCenter: parent.verticalCenter
//        }
//        Text {
//            text: AppClient.App.makeAccisable("service_name|function_name", index, userList.model)[1]
//            font.bold: true
//            anchors.verticalCenter: parent.verticalCenter
//        }
//        Text{
//            text: userList.model.auth_object(index, false).getModelValue(0, "auth_object_id")
//        }
//    }
//}

TableView{
        id: userList

        property variant myDashboard;
        function setDashboard(dashboard){
            myDashboard = dashboard;
            console.log(myDashboard.source);
        }
            model: TableModel {
                TableModelColumn {
                    display: function(modelIndex) {
                        return AppClient.App.makeAccisable("service_name|function_name", modelIndex.row, myDashboard.userListModel)[1];
                    }

                }
                columnCount: 1
                rowCount: myDashboard.userListModel.getRowCount()

            }
           width: parent.width
            height: childrenRect.height
}

/*##^##
Designer {
    D{i:1;anchors_width:0}
}
##^##*/
