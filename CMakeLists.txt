# general info  
cmake_minimum_required(VERSION 3.30)  
set(PROJECT_NAME SomePractice)  
project(${PROJECT_NAME} VERSION 1.0.0)  
message ("----------------Project File Generation for ${PROJECT_NAME}----------------- ")  

# common options  
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)  
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})  

# cpp options  
set(CMAKE_CXX_STANDARD 20)  
set(CMAKE_CXX_STANDARD_REQUIRED True)  

# Recources
file(GLOB_RECURSE SOURCES "Source/*.cpp")  
file(GLOB_RECURSE INCLUDES "Source/*.h")  

# Include
include_directories(Source)  

add_executable(${PROJECT_NAME} ${SOURCES} ${INCLUDES})   

message ("-------Project Files Generated--------")  