Cmake_minimum_required(VERSION 3.12) #小于3.12没法findpython

project(demo_example)
#添加当前目录下的所有代码
set(CMAKE_CXX_STANDARD 17)
#找opencv
find_package(Eigen3)
find_package(Ceres REQUIRED)
find_package(OpenCV REQUIRED)
find_package(pybind11 REQUIRED)
find_package(glog REQUIRED)
#python写自己ubuntu带的版本
find_package(Python3 3.10.7 EXACT REQUIRED COMPONENTS Development Interpreter)
include_directories(
	include 
	${EIGEN3_INCLUDE_DIR} 
	${CERES_INCLUDE_DIRS} 
	${GLOG_INCLUDE_DIRS} 
	${PYBIND11_INCLUDE_DIRS} 
	)

#生成可执行文件
add_executable(
		demo_example 
		src/c++/cppcode/main.cpp
		src/c++/hppcode/demo_example.hpp
		src/general/c++/using_python.hpp
		src/general/c++/using_glog.hpp
)
#gxiapi是大恒相机的必须链接
target_link_libraries(demo_example ${OpenCV_LIBS} ${X11_LIBRARIES} ${CERES_LIBRARIES} gxiapi pthread)
target_link_libraries(demo_example Python3::Python pybind11::pybind11 glog)
