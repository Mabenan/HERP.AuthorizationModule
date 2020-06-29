import QtQuick 2.13
import QtQuick.Controls 2.13
import Qt.labs.qmlmodels 1.0
import com.applicationclient 1.0 as AppClient

TableView{
        id: userList

        columnSpacing: 1
        rowSpacing: 1
        clip: true
        property variant myDashboard;
        function setDashboard(dashboard){
            myDashboard = dashboard;
            console.log(myDashboard.source);
        }
        model: myDashboard.userListModel
        delegate: Rectangle {
                implicitWidth: 200
                implicitHeight: 100
                border.width: 1
                color: "grey"
                Text {
                    text: display
                    anchors.centerIn: parent
                }
            }
           width: parent.width
            height: childrenRect.height
}

/*##^##
Designer {
    D{i:1;anchors_width:0}
}
##^##*/
