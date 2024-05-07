cmake_minimum_required(VERSION 3.8)
project(viper_cpp)

set(CMAKE_CXX_STANDARD 17)  # Set the C++ standard
set(CMAKE_CXX_EXTENSIONS ON)  # Enable GNU extensions

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBUSB REQUIRED libusb-1.0)

# Include directories for libusb
include_directories(${LIBUSB_INCLUDE_DIRS})
# Source files - Add all relevant source files here
set(SOURCE_FILES 
  src/viperConnect.cpp
  src/viper_ui.cpp
  src/viper_usb.cpp
  src/viper_queue.cpp
)

# Define the executable(s)
add_executable(viper_node 
  ${SOURCE_FILES}
)

# Dependency linking for ROS 2
ament_target_dependencies(viper_node rclcpp)

# Linking against libusb and pthread
target_link_libraries(viper_node 
  ${LIBUSB_LIBRARIES}
  pthread  # Linking pthread if needed for threading
)

install(TARGETS
  viper_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
