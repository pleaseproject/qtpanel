cmake_minimum_required(VERSION 2.8.3)
project(qtpanel)
find_package(X11 REQUIRED)
option(USE_QT5 "Build against Qt5 instead of Qt4." OFF)
if(USE_QT5)
    message(STATUS "Use Qt5")
    find_package(Qt5Core REQUIRED)
    find_package(Qt5Widgets REQUIRED)
    find_package(Qt5X11Extras REQUIRED)
else()
    find_package(Qt4 REQUIRED)
endif()
set(qtpanel_UIS
	panelapplicationsettings.ui
)
set(qtpanel_HEADERS
	dpisupport.h
    iconloader.h
	textgraphicsitem.h
	animationutils.h
)
set(qtpanel_MOC_HEADERS
    x11support.h
	desktopapplications.h
	panelapplication.h
	panelwindow.h
	applet.h
	demoapplet.h
	spacerapplet.h
	clockapplet.h
	applicationsmenuapplet.h
	dockapplet.h
	trayapplet.h
)
set(qtpanel_SOURCES
	dpisupport.cpp
	iconloader.cpp
	x11support.cpp
	desktopapplications.cpp
	main.cpp
	panelapplication.cpp
	panelwindow.cpp
	textgraphicsitem.cpp
	applet.cpp
	demoapplet.cpp
	spacerapplet.cpp
	clockapplet.cpp
	applicationsmenuapplet.cpp
	dockapplet.cpp
	trayapplet.cpp
)
if(USE_QT5)
    include_directories(${Qt5Widgets_INCLUDE_DIRS} ${Qt5Widgets_LIBRARIES} ${Qt5X11Extras_INCLUDE_DIRS} ${Qt5X11Extras_LIBRARIES} ${Qt5Declarative_INCLUDE_DIRS} ${Qt5Declarative_LIBRARIES})
    add_definitions(${Qt5Widgets_DEFINITIONS})
    add_definitions(${Qt5X11Extras_DEFINITIONS})
    qt5_wrap_ui(qtpanel_UI_HEADERS ${qtpanel_UIS})
    qt5_wrap_cpp(qtpanel_MOC_OUTPUT ${qtpanel_MOC_HEADERS})
else()
    include(${QT_USE_FILE})
    add_definitions(${QT_DEFINITIONS})
    qt4_wrap_ui(qtpanel_UI_HEADERS ${qtpanel_UIS})
    qt4_wrap_cpp(qtpanel_MOC_OUTPUT ${qtpanel_MOC_HEADERS})
endif()
include_directories(${CMAKE_BINARY_DIR})
add_executable(qtpanel ${qtpanel_SOURCES} ${qtpanel_MOC_OUTPUT} ${qtpanel_HEADERS} ${qtpanel_UI_HEADERS})
if(USE_QT5)
    target_link_libraries(qtpanel Qt5::Widgets Qt5::X11Extras ${X11_LIBRARIES} ${X11_Xcomposite_LIB} ${X11_Xdamage_LIB})
else()
    target_link_libraries(qtpanel ${QT_LIBRARIES} ${X11_LIBRARIES} ${X11_Xcomposite_LIB} ${X11_Xdamage_LIB})
endif()
