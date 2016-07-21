find_package( Boost 1.60 COMPONENTS system REQUIRED )
find_package( Threads REQUIRED )


if( Boost_FOUND )
  
  set( CMAKE_CXX_FLAGS "-std=c++11 -O3" )

  include_directories( ${Boost_INCLUDE_DIRS} )
  include_directories( serial/include )

  link_directories( ${Boost_LIBRARY_DIRS} )
  
  add_subdirectory( benchmarks )
  
endif()
