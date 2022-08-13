cmake_minimum_required(VERSION 3.16)
project(qmarkdowntextedit LANGUAGES CXX)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
#set(CMAKE_CXX_STANDARD 11) Use this instead
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(QT_QML_OUTPUT_DIRECTORY  ${CMAKE_BINARY_DIR})

# add option to disable test executable
option(QMARKDOWNTEXTEDIT_EXE "Build test executable" ON)

# find qt
find_package(Qt6 REQUIRED COMPONENTS Widgets Quick Qml)

# needed for windows
if(WIN32)
    set(INTL_LDFLAGS -lintl)
endif(WIN32)

# QMarkdownTextEdit library
set(RC_FILES
    media.qrc
)

# Translations arent loaded so don't include them
set(TS_FILES
    trans/qmarkdowntextedit_de.ts
    trans/qmarkdowntextedit_ur.ts
    trans/qmarkdowntextedit_zh_CN.ts
)

set(QMARKDOWNTEXTEDIT_FILES
    markdownhighlighter.h
    markdownhighlighter.cpp
    linenumberarea.h
    qmarkdowntextedit.h
    qmarkdowntextedit.cpp
    qownlanguagedata.h
    qownlanguagedata.cpp
    qplaintexteditsearchwidget.h
    qplaintexteditsearchwidget.ui
    qplaintexteditsearchwidget.cpp
    media.qrc
)

qt_add_library(qmarkdowntextedit STATIC ${QMARKDOWNTEXTEDIT_FILES})

target_link_libraries(qmarkdowntextedit PRIVATE Qt::Widgets Qt::Quick ${INTL_LDFLAGS})

qt_add_qml_module(qmarkdowntextedit
    URI QMarkdownTextEdit
    VERSION 1.0
    # QML_FILES app.qml
    # NO_RESOURCE_TARGET_PATH
    SOURCES ${QMARKDOWNTEXTEDIT_FILES}
)

target_include_directories(qmarkdowntextedit PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# QMarkdownTextEdit executable
if(QMARKDOWNTEXTEDIT_EXE)
    set(SOURCE_FILES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
    )

    add_executable(qmarkdowntextedit-exe ${SOURCE_FILES})
    target_link_libraries(qmarkdowntextedit-exe Qt${QT_VERSION_MAJOR}::Widgets ${INTL_LDFLAGS} qmarkdowntextedit)
endif()

# Example Project
qt_add_executable(ExampleProject example/example.cpp)
qt_add_qml_module(ExampleProject
    URI ExampleProjectApp
    VERSION 1.0
    QML_FILES example/example.qml
)
target_link_libraries(ExampleProject PRIVATE Qt6::Quick Qt::Widgets qmarkdowntexteditplugin)
