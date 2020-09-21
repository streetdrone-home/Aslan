cmake_minimum_required(VERSION 2.8.3)
project(aslan_gui)

find_package(catkin REQUIRED COMPONENTS
		rospy)
find_package(aslan_msgs REQUIRED)

catkin_install_python(PROGRAMS
		scripts/aslan_gui.py
		scripts/aslan_wizard.py
		DESTINATION share/${PROJECT_NAME})

install(FILES
        scripts/cameras.yaml
		scripts/planning.yaml
		scripts/controls.yaml
		scripts/param.yaml
		scripts/radar.yaml
		scripts/simulation.yaml
		scripts/topics.yaml
		scripts/perception.yaml
		scripts/tools.yaml
		scripts/vehicle.yaml
		scripts/aslan_gui.wxg
  DESTINATION share/${PROJECT_NAME})

catkin_package(
        CATKIN_DEPENDS rospy std_msgs aslan_msgs
)

install(DIRECTORY launch/
        DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/launch
        PATTERN ".svn" EXCLUDE)

install(DIRECTORY scripts/imgs/
        DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/imgs
        PATTERN ".svn" EXCLUDE)

install(FILES scripts/Aslan_Icon.png scripts/Aslan_Autonomy.png
        DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})