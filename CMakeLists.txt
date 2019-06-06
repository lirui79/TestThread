# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)
# 项目信息
project (Test)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量

AUX_SOURCE_DIRECTORY(. DIR_TEST_SRCS)

add_executable( Test ${DIR_TEST_SRCS})
target_link_libraries(Test  pthread)