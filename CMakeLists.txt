cmake_minimum_required(VERSION 3.5)

project(
  myPicAlgo
  VERSION 0.1
  LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# include_directories("E:\\opencv4.5.1\\opencv\\opencv-build\\install\\include")
include_directories(${OPENCV_INC})
set(LIBS
    E:/opencv4.5.1/opencv/opencv-build/lib/libopencv_imgcodecs451.dll.a
    E:/opencv4.5.1/opencv/opencv-build/lib/libopencv_dnn451.dll.a
    E:/opencv4.5.1/opencv/opencv-build/lib/libopencv_imgproc451.dll.a
    E:/opencv4.5.1/opencv/opencv-build/lib/libopencv_core451.dll.a
    E:/opencv4.5.1/opencv/opencv-build/lib/libopencv_features2d451.dll.a
    E:/opencv4.5.1/opencv/opencv-build/lib/libopencv_flann451.dll.a
    E:/opencv4.5.1/opencv/opencv-build/lib/libopencv_gapi451.dll.a
    E:/opencv4.5.1/opencv/opencv-build/lib/libopencv_highgui451.dll.a
    E:/opencv4.5.1/opencv/opencv-build/lib/libopencv_calib3d451.dll.a
    E:/opencv4.5.1/opencv/opencv-build/lib/libopencv_ml451.dll.a
    E:/opencv4.5.1/opencv/opencv-build/lib/libopencv_objdetect451.dll.a
    E:/opencv4.5.1/opencv/opencv-build/lib/libopencv_photo451.dll.a
    E:/opencv4.5.1/opencv/opencv-build/lib/libopencv_stitching451.dll.a
    E:/opencv4.5.1/opencv/opencv-build/lib/libopencv_ts451.a
    E:/opencv4.5.1/opencv/opencv-build/lib/libopencv_video451.dll.a
    E:/opencv4.5.1/opencv/opencv-build/lib/libopencv_videoio451.dll.a
    E:/opencv4.5.1/opencv/opencv-build/lib/libade.a)

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    dft.cpp
    dft.h
    dft.ui
    lsb.cpp
    lsb.h
    lsb.ui)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
  qt_add_executable(myPicAlgo MANUAL_FINALIZATION ${PROJECT_SOURCES})
  # Define target properties for Android with Qt 6 as: set_property(TARGET
  # myPicAlgo APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
  # ${CMAKE_CURRENT_SOURCE_DIR}/android) For more information, see
  # https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
  if(ANDROID)
    add_library(myPicAlgo SHARED ${PROJECT_SOURCES})
    # Define properties for Android with Qt 5 after find_package() calls as:
    # set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
  else()
    add_executable(myPicAlgo ${PROJECT_SOURCES})
  endif()
endif()

target_link_libraries(myPicAlgo PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(myPicAlgo PRIVATE ${OpenCV_LIBS})

set_target_properties(
  myPicAlgo
  PROPERTIES MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
             MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
             MACOSX_BUNDLE_SHORT_VERSION_STRING
             ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
             MACOSX_BUNDLE TRUE
             WIN32_EXECUTABLE TRUE)

if(QT_VERSION_MAJOR EQUAL 6)
  qt_finalize_executable(myPicAlgo)
endif()
