#include(../RibiLibraries/Apfloat.pri)
include(../RibiLibraries/Fparser.pri)
include(../RibiLibraries/GeneralConsole.pri)

#Specific, console
include(../RibiClasses/CppCanvas/CppCanvas.pri)
include(../RibiClasses/CppContainer/CppContainer.pri)
include(../DotMatrix/DotMatrix.pri)
include(../RibiClasses/CppDrawCanvas/CppDrawCanvas.pri)
include(../RibiClasses/CppFuzzy_equal_to/CppFuzzy_equal_to.pri)
include(../RibiClasses/CppGeometry/CppGeometry.pri)
include(../plane/plane.pri)
include(../RibiClasses/CppRibiRegex/CppRibiRegex.pri)
include(../RibiClasses/CppXml/CppXml.pri)

#Specific, desktop
include(FunctionPlotterConsole.pri)

SOURCES += main.cpp

# C++14
CONFIG += c++14
QMAKE_CXX = g++-5
QMAKE_LINK = g++-5
QMAKE_CC = gcc-5
QMAKE_CXXFLAGS += -std=c++14

# High warning levels
# Qt combines bad with -Weffc++
# fparser does not work with -Wshadow
QMAKE_CXXFLAGS += -Wall -Wextra  -Wnon-virtual-dtor -pedantic -Werror

# Debug and release mode
CONFIG += debug_and_release

# In release mode, define NDEBUG
CONFIG(release, debug|release) {

  DEFINES += NDEBUG
}

# In debug mode, turn on gcov and UBSAN
CONFIG(debug, debug|release) {

  # gcov
  QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
  LIBS += -lgcov

  # UBSAN
  QMAKE_CXXFLAGS += -fsanitize=undefined
  QMAKE_LFLAGS += -fsanitize=undefined
  LIBS += -lubsan
}

# Qt
QT += core

# Fixes
#/usr/include/boost/math/constants/constants.hpp:277: error: unable to find numeric literal operator 'operator""Q'
#   BOOST_DEFINE_MATH_CONSTANT(half, 5.000000000000000000000000000000000000e-01, "5.00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e-01")
#   ^
QMAKE_CXXFLAGS += -fext-numeric-literals

