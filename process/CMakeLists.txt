set (GCC_COVERAGE_COMPILE_FLAGS "-fexec-charset=EUC-KR")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

ADD_EXECUTABLE(target read_memory/target.cpp)
ADD_EXECUTABLE(read_memory read_memory/readprocessmemory.cpp)
ADD_EXECUTABLE(sample create_process/sample.cpp)
ADD_EXECUTABLE(create_process create_process/create_process.cpp)
