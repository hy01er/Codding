cmake_minimum_required(VERSION 3.21)
project(MyCodeUint)

set(CMAKE_CXX_STANDARD 14)

add_executable(MyCodeUint main.cpp src/basic/type/basic_type.h src/data_structure/linklist.h src/algorithm/ha_sort/ha_sort.h src/algorithm/ha_sort/ha_sort_bubble.cpp src/algorithm/ha_sort/ha_sort.cpp src/algorithm/ha_sort/ha_sort_selection.cpp src/algorithm/ha_sort/ha_sort_insert.cpp src/algorithm/ha_sort/ha_sort_quick.cpp src/algorithm/ha_sort/ha_sort_merge.cpp src/algorithm/ha_math/ha_math.h src/algorithm/ha_math/ha_math_add.cpp src/algorithm/ha_math/ha_math_subtract.cpp src/algorithm/ha_math/ha_math_multiply.cpp src/algorithm/ha_math/ha_math_division.cpp src/data_structure/linklist.cpp src/data_structure/stack.cpp src/data_structure/stack.h src/data_structure/queue.cpp src/data_structure/queue.h src/test/recursive.cpp src/basic/print/basic_print.h src/basic/print/basic_print_array.cpp)