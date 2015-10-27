# Author : Weipeng He <heweipeng@gmail.com>
# Copyright (c) 2015, All rights reserved.

add_executable(triangle triangle.c)
target_link_libraries(triangle ${GSL_LIBRARIES})

add_executable(square square.c)
target_link_libraries(square ${GSL_LIBRARIES})

add_executable(var var.c)
target_link_libraries(var ${GSL_LIBRARIES} m)

