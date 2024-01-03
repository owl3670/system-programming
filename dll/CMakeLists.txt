set (GCC_COVERAGE_COMPILE_FLAGS "-fexec-charset=EUC-KR")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

ADD_LIBRARY(sample.dll SHARED sample/sample.cpp)
ADD_EXECUTABLE(apihook2 apihook/apihook2.cpp)
ADD_EXECUTABLE(apihook4 apihook/apihook4.cpp)