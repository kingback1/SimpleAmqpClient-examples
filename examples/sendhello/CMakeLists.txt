# face recognition
project(sendhello)
cmake_minimum_required(VERSION 2.8)

# 配置OpenCV,设置环境变量`OpenCV_DIR`指向OpenCV的build文件夹路径
# `OpenCV_DIR` --> `/path/to/opencv/build`
# 保证`OpenCV_DIR/(x86|x64)/(vc10|vc11|vc12)/bin`路径在系统Path中
find_package(OpenCV REQUIRED)
find_package (Threads)

#FIND_PACKAGE(Boost 1.57.0 COMPONENTS chrono system REQUIRED)
LINK_DIRECTORIES(SYSTEM D:/360Downloads/boost_1_57_0/stage/lib)
INCLUDE_DIRECTORIES(SYSTEM "D:/360Downloads/boost_1_57_0")

#FIND_PACKAGE(SimpleAmqpClient REQUIRED)
INCLUDE_DIRECTORIES(SYSTEM "E:/GIT/SimpleAmqpClient/src")
LINK_DIRECTORIES(SYSTEM "E:/GIT/SimpleAmqpClient/simpleamqpclient-build/Debug")

#FIND_PACKAGE(Rabbitmqc REQUIRED)
INCLUDE_DIRECTORIES(SYSTEM "E:/GIT/rabbitmq-c-0.5.2/librabbitmq")
LINK_DIRECTORIES(SYSTEM "E:/GIT/rabbitmq-c-0.5.2/build/librabbitmq/Debug")

# add c++11 flags for gcc
if (CMAKE_COMPILER_IS_GNUCXX)
    set(ENABLE_CXX11 "-std=c++11")
    if (GCC_VERSION VERSION_LESS 4.7)
        set(ENABLE_CXX11 "-std=c++0x")
    endif()

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${ENABLE_CXX11}")
endif()

include_directories(.)
file(GLOB SOURCE *.h* *.c*)
#INCLUDE_DIRECTORIES(SYSTEM ${SimpleAmqpClient_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${SOURCE})
target_link_libraries(${PROJECT_NAME} SimpleAmqpClient.2 rabbitmq.1 ${OpenCV_LIBS} ${CMAKE_THREAD_LIBS_INIT} )
