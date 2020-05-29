import QtQuick 2.0
Item {

    property variant myDashboard;
    function setDashboard(dashboard){
        myDashboard = dashboard;
        console.log(myDashboard.source);
    }

    Rectangle{
        width: childrenRect.width
        height: childrenRect.height
        color:  "green";

        ListView {
            id: listView
            model: myDashboard.userListModel
            width: 110
            height: 160
            delegate: Item {
                x: 5
                width: 80
                height: 40
                Row {
                    id: row1

                    Text {
                        text: auth_user_name
                        font.bold: true
                        anchors.verticalCenter: parent.verticalCenter
                    }
                    spacing: 10
                }
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
