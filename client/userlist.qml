import QtQuick 2.13
import QtQuick.Controls 2.13
import Qt.labs.qmlmodels 1.0
import com.applicationclient 1.0 as AppClient

Item {
    id: userlistItem
    width: parent.width
    height: childrenRect.height
    property variant myDashboard;
    function setController(dashboard){
        myDashboard = dashboard;
        console.log(myDashboard.source);
    }

    Button{
        text: "Save"
        onClicked: {
            myDashboard.userListModel.qxSave_(["*->*"]);
        }
    }

TableView{
    id: userList

    columnSpacing: 1
    rowSpacing: 1
    clip: true
    width: parent.width
    height: childrenRect.height
    anchors.top: parent.top
    anchors.topMargin: 50
    model: myDashboard.userListModel
    delegate: DelegateChooser {
        DelegateChoice {
            column: 0
            delegate:Rectangle {
                implicitWidth: 200
                implicitHeight: 100
                border.width: 1
                color: "grey"
                Label {
                    text: model.display
                }
            }
        }
        DelegateChoice {
            delegate:
                Rectangle {
                implicitWidth: 200
                implicitHeight: 100
                border.width: 1
                color: "grey"
                TextInput {
                    text: model.edit
                    padding: 12
                    selectByMouse: true

                    onAccepted: model.edit = text

                    Rectangle {
                        anchors.fill: parent
                        color: "#efefef"
                        z: -1
                    }
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
