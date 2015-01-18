TEMPLATE = app
CONFIG += console
CONFIG -= qt
CONFIG += debug



#DESTDIR += bin
CONFIG  += x86_64


OBJECTS_DIR = .tmp
MOC_DIR = .tmp
UI_DIR = .tmp
RCC_DIR = .tmp


QMAKE_CXXFLAGS += -gdwarf-3


QMAKE_CFLAGS_DEBUG += -O0
QMAKE_CFLAGS_RELEASE += -O2

QMAKE_CXXFLAGS_DEBUG += -O0
QMAKE_CXXFLAGS_DEBUG += -std=c++0x
QMAKE_CXXFLAGS_DEBUG += -Wparentheses
QMAKE_CXXFLAGS_DEBUG += -Wreturn-type
QMAKE_CXXFLAGS_DEBUG += -Wshadow
QMAKE_CXXFLAGS_DEBUG += -Wextra
QMAKE_CXXFLAGS_DEBUG += -Wunused-parameter
QMAKE_CXXFLAGS_DEBUG -= -Wwrite-strings
QMAKE_CXXFLAGS_DEBUG += -Wno-unused-variable
QMAKE_CXXFLAGS_DEBUG += -Wno-unused-function
QMAKE_CXXFLAGS_DEBUG += -Weffc++
QMAKE_CXXFLAGS_DEBUG += -Wignored-qualifiers
QMAKE_CXXFLAGS_DEBUG += -Wparentheses
QMAKE_CXXFLAGS_DEBUG += -Wreturn-type
QMAKE_CXXFLAGS_DEBUG += -Wshadow
QMAKE_CXXFLAGS_DEBUG += -Wextra
QMAKE_CXXFLAGS_DEBUG += -Wunused-parameter

QMAKE_CXXFLAGS_DEBUG += -Wwrite-strings
QMAKE_CXXFLAGS_DEBUG += -Wno-unused-variable
QMAKE_CXXFLAGS_DEBUG += -Wpedantic
QMAKE_CXXFLAGS_DEBUG += -Wno-unused-but-set-variable
QMAKE_CXXFLAGS_DEBUG += -Werror
QMAKE_CXXFLAGS_DEBUG += -Wall
QMAKE_CXXFLAGS_DEBUG += -Wcast-align
QMAKE_CXXFLAGS_DEBUG += -Wcast-qual
QMAKE_CXXFLAGS_DEBUG += -Woverloaded-virtual
QMAKE_CXXFLAGS_DEBUG += -Wzero-as-null-pointer-constant
QMAKE_CXXFLAGS_DEBUG += -Wwrite-strings
QMAKE_CXXFLAGS_DEBUG += -Wconversion
QMAKE_CXXFLAGS_DEBUG += -Wold-style-cast


QMAKE_CXXFLAGS_RELEASE += -O2
QMAKE_CXXFLAGS_RELEASE += -std=c++0x
QMAKE_CXXFLAGS_RELEASE += -Wparentheses
QMAKE_CXXFLAGS_RELEASE += -Wreturn-type
QMAKE_CXXFLAGS_RELEASE += -Wshadow
QMAKE_CXXFLAGS_RELEASE += -Wextra
QMAKE_CXXFLAGS_RELEASE += -Wunused-parameter
QMAKE_CXXFLAGS_RELEASE -= -Wwrite-strings
QMAKE_CXXFLAGS_RELEASE -= -Wunused-variable
#QMAKE_CXXFLAGS_RELEASE += -Weffc++


SOURCES +=  \
    src/main.cpp \
    src/filefn/t_filename.cpp \
    src/hstring/stringhelper.cpp \
    src/hstring/gettokens.cpp \
    src/hfile/filehelper.cpp \
    src/hstring/t_2D_string.cpp \
    src/htime/timer.cpp \
    src/hfile/fn_control.cpp \
    src/filefn/filetreewalk.cpp


HEADERS += \
    src/filefn/t_filename.h \
    src/hstring/stringhelper.h \
    src/hstring/gettokens.h \
    src/hstring/filehelper.h \
    src/txtrw/wList.h \
    src/txtrw/rList.h \
    src/hfile/filehelper.h \
    src/boost/boost_cstdint.h \
    src/minit/tObjPositionSize.h \
    src/minit/tLine.h \
    src/minit/tIndexID.h \
    src/minit/tArea.h \
    src/minit/t_3D_xyz.h \
    src/minit/t_2D_xy.h \
    src/minit/t_2D_Matrix.h \
    src/htime/timer.h \
    src/hfile/fn_control.h \
    src/filefn/filetreewalk.h \
    src/filefn/filetreewalk_ref.h

INCLUDEPATH += $$PWD/src
INCLUDEPATH += $$PWD/src/minit
INCLUDEPATH += $$PWD/src/hstring
INCLUDEPATH += $$PWD/src/hfile
INCLUDEPATH += $$PWD/src/filefn
INCLUDEPATH += $$PWD/src/ftw
INCLUDEPATH += $$PWD/src/txtrw
INCLUDEPATH += $$PWD/src/htime


LIBS = -lboost_system -lboost_filesystem

OTHER_FILES += \
    lgpl-3.0.txt \
    README.md \
    Funktionen.txt
