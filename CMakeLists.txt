# Project
project(qsyncable)

find_package(Qt5 ${QT_REQUIRED_VERSION} CONFIG REQUIRED COMPONENTS Gui Qml)

# Target
add_library(${PROJECT_NAME} SHARED "")
# Include
target_include_directories(${PROJECT_NAME} PUBLIC "./")
set_target_properties(qsyncable PROPERTIES AUTOMOC ON)

# Sources
file(GLOB SOURCES "./*")
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})

# Libraries
target_link_libraries(${PROJECT_NAME} PUBLIC Qt5::Core Qt5::Qml)
