import QtQuick 2.13
import QtQuick.Controls 2.13
import com.applicationclient 1.0 as AppClient
Item {
    id: element
    width: window.width - 16
    height: childrenRect.height

    property variant myDashboard;
    function setDashboard(dashboard){
        myDashboard = dashboard;
        console.log(myDashboard.source);
    }

    Rectangle{
        color:  "green";
        height: childrenRect.height
        width: window.width - 16
        visible: true

        ListView {
            id: userList
            model: myDashboard.userListModel
            height: childrenRect.height
            delegate:
                Row {
                                 spacing: 10

                                 Text {
                                     text: index
                                     font.bold: true
                                     anchors.verticalCenter: parent.verticalCenter
                                 }
                                 Text {
                                     text: AppClient.App.makeAccisable("service_name|function_name", index, userList.model)[0]
                                     font.bold: true
                                     anchors.verticalCenter: parent.verticalCenter
                                 }
                                 Text {
                                     text: AppClient.App.makeAccisable("service_name|function_name", index, userList.model)[1]
                                     font.bold: true
                                     anchors.verticalCenter: parent.verticalCenter
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
