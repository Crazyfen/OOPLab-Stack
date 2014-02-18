cmake_minimum_required(VERSION 2.8)	 

project(Container)	

set(SOURCE_PATH "src/")
set(SOURCE_EXE "${SOURCE_PATH}main.cpp")		
set(SOURCE_LIB "${SOURCE_PATH}container.cpp")	

add_library(container STATIC ${SOURCE_LIB})	
add_executable(main ${SOURCE_EXE})	

target_link_libraries(main container)		