
add_executable( simple src/simple.cpp )
target_link_libraries( simple ${Boost_SYSTEM_LIBRARY} )
target_link_libraries( simple ${CMAKE_THREAD_LIBS_INIT} )
