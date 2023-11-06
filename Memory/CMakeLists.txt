set (GCC_COVERAGE_COMPILE_FLAGS "-fexec-charset=EUC-KR")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

ADD_EXECUTABLE(valloc2 valloc/valloc2.cpp)