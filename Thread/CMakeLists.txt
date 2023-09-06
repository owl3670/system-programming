set (GCC_COVERAGE_COMPILE_FLAGS "-fexec-charset=EUC-KR")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

ADD_EXECUTABLE(create_thread1 create_thread/create_thread1.cpp)
ADD_EXECUTABLE(create_thread2 create_thread/create_thread2.cpp)
