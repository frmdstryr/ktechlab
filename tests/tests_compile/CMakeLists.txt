
set(SRC_DIR ${PROJECT_SOURCE_DIR}/src/)

include_directories(
    ${SRC_DIR}  # needed for subdirs
    ${SRC_DIR}/core
    ${CMAKE_BINARY_DIR}/src/core  # for the kcfg file
    ${SRC_DIR}/drawparts
    ${SRC_DIR}/electronics
    ${SRC_DIR}/electronics/components
    ${SRC_DIR}/electronics/simulation
    ${SRC_DIR}/flowparts
    ${SRC_DIR}/gui
    ${CMAKE_BINARY_DIR}/src/gui  # for ui-generated files
    ${SRC_DIR}/gui/itemeditor
    ${SRC_DIR}/languages
    ${SRC_DIR}/mechanics
    ${SRC_DIR}/micro
    ${KDE4_INCLUDES}
    ${QT_INCLUDES})
if(GPSim_FOUND)
    include_directories(${GPSim_INCLUDE_DIRS})
    set(CMAKE_CXX_FLAGS ${KDE4_ENABLE_EXCEPTIONS})
endif()

add_executable(test_compile test_compile.cpp)

target_link_libraries( test_compile
    test_ktechlab
    #core 
#     gui micro flowparts
#     ktlqt3support
#     mechanics electronics elements components languages drawparts
#     itemeditor
#     test_ktechlab
#     math

    ${GPSIM_LIBRARY}
	${QT_QTXML_LIBRARY}
	${QT_QTGUI_LIBRARY} # QtGui
	${QT_QTCORE_LIBRARY} # QtCore
	KF5::ConfigCore
	KF5::ConfigGui
	KF5::KIOCore
	KF5::KHtml
	KF5::CoreAddons
	KF5::XmlGui
	KF5::TextEditor
	KF5::KDELibs4Support
    )
if(GPSim_FOUND)
    target_link_libraries(test_compile ${GPSim_LIBRARIES})
endif()
