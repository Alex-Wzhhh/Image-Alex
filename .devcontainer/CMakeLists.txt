cmake_minimum_required(VERSION 3.20)
project(WSIPrototype LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

# 使用 pkg-config 查找 OpenSlide / OpenCV
find_package(PkgConfig REQUIRED)
pkg_check_modules(OPENSLIDE REQUIRED openslide)
pkg_check_modules(OPENCV REQUIRED opencv4)

# 核心库（与 Qt 解耦，后续在 Qt 中直接链接）
add_library(wsi_core src/wsi_reader.cpp)
target_include_directories(wsi_core PUBLIC include ${OPENSLIDE_INCLUDE_DIRS} ${OPENCV_INCLUDE_DIRS})
target_link_libraries(wsi_core PUBLIC ${OPENSLIDE_LIBRARIES} ${OPENCV_LIBRARIES})
target_compile_options(wsi_core PRIVATE ${OPENSLIDE_CFLAGS_OTHER} ${OPENCV_CFLAGS_OTHER})

# 控制台示例程序
add_executable(wsi_demo app/main.cpp)
target_link_libraries(wsi_demo PRIVATE wsi_core)
