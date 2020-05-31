import QtQuick 2.0
import QtQuick.Controls 2.13
import QtQuick.Layouts 1.3

Item {
    id: element2

    property variant myDashboard;
    function setDashboard(dashboard){
        myDashboard = dashboard;
        console.log(myDashboard.source);
    }

    Rectangle{

        width: window.width - 16
        height: childrenRect.height
        color:  "green";

        GridLayout {
            id: gridLayout
            height: 200
            rows: 3
            columns: 2
            anchors.right: parent.right
            anchors.rightMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 0


            Text {
                id: element
                text: qsTr("Username")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                Layout.fillHeight: true
                Layout.fillWidth: false
                font.pixelSize: 30
            }

            TextField {
                id: username
                text: qsTr("")
                Layout.fillHeight: true
                Layout.fillWidth: true
            }

            Text {
                id: element1
                text: qsTr("Password")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                Layout.fillHeight: true
                Layout.fillWidth: false
                font.pixelSize: 30
            }

            TextField {
                id: password
                text: qsTr("")
                Layout.fillHeight: true
                Layout.fillWidth: true
                echoMode: TextInput.Password
            }

            Button {
                id: button
                text: qsTr("Login")
                Layout.columnSpan: 2
                Layout.fillHeight: true
                Layout.fillWidth: true

                Connections {
                    target: button
                    onClicked: {
                        myDashboard.login(username.text, password.text);
                    }
                }
            }


        }

    }
}

/*##^##
Designer {
    D{i:2;anchors_height:100;anchors_width:100}
}
##^##*/
