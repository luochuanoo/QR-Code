# 声明要求的cmake最低版本
cmake_minimum_required(VERSION 2.8)
# 声明一个cmake工程
project(QR_Code)

# Check C++11 support
set(CMAKE_CXX_FLAGS "-std=c++11")

# 打印相关消息消息
MESSAGE(STATUS "Project: SERVER")

find_package(OpenCV 3 REQUIRED)
# find_package(Zbar REQUIRED)

# 头文件
include_directories(
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/include
) 

# 设置路径（下面生成共享库的路径）
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
# 即生成的共享库在工程文件夹下的lib文件夹中

# # 创建共享库（把工程内的cpp文件都创建成共享库文件，方便通过头文件来调用）
add_library (${PROJECT_NAME} SHARED
    src/common.cpp
)

# 导入静态库 .a 文件
#add_library(gxiapi SHARED IMPORTED)
#set_target_properties(  gxiapi
#                        PROPERTIES IMPORTED_LOCATION
#                        ${PROJECT_SOURCE_DIR}/libgxiapi.a  
#)

# 导入动态库 .so 文件
link_directories (
    ${PROJECT_SOURCE_DIR}/lib
) #添加动态连接库的路径

# 链接库
# 把生成的 ${PROJECT_NAME} 库和所需的其它库链接起来
target_link_libraries ( ${PROJECT_NAME}
    ${OpenCV_LIBS}
)

# 存放 association 生成的二进制文件
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

add_executable(zbar_detect zbar_detect.cpp)
target_link_libraries(zbar_detect ${PROJECT_NAME} -lzbar)

add_executable(opencv_detect opencv_detect.cpp)
target_link_libraries(opencv_detect ${PROJECT_NAME})

add_executable(dmtx_detect dmtx_detect.cpp)
target_link_libraries(dmtx_detect ${PROJECT_NAME} -ldmtx)