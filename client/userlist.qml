import QtQuick 2.13
import QtQuick.Controls 2.13
import com.applicationclient 1.0 as AppClient
Item {
    id: element
    width: window.width - 16

    property variant myDashboard;
    function setDashboard(dashboard){
        myDashboard = dashboard;
        console.log(myDashboard.source);
    }

    Rectangle{
        color:  "green";
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        height: childrenRect.height

        ListView {
            id: userList
            model: myDashboard.userListModel
            height: 300
            y: 30
            anchors.fill: parent
            delegate: Rectangle {
                Row {
                                 height: 20
                                 spacing: 10

                                 Text {
                                     text: userList.currentIndex
                                     font.bold: true
                                     anchors.verticalCenter: parent.verticalCenter
                                 }
                                 Text {
                                     text: AppClient.App.makeAccisable("service_name|function_name", userList.currentIndex, userList.model)[0]
                                     font.bold: true
                                     anchors.verticalCenter: parent.verticalCenter
                                 }
                                 Text {
                                     text: AppClient.App.makeAccisable("service_name|function_name", userList.currentIndex, userList.model)[1]
                                     font.bold: true
                                     anchors.verticalCenter: parent.verticalCenter
                                 }
                             }
                        }
        }
    }
}

/*##^##
Designer {
    D{i:1;anchors_width:0}
}
##^##*/
