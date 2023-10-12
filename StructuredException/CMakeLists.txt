set (GCC_COVERAGE_COMPILE_FLAGS "-fexec-charset=EUC-KR")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

ADD_EXECUTABLE(seh1 seh/seh1.cpp)
ADD_EXECUTABLE(seh2 seh/seh2.cpp)
ADD_EXECUTABLE(seh3 seh/seh3.cpp)
