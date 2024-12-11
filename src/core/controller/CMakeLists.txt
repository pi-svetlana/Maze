set(target controller)

add_library(${target}
        SHARED
        controller.cc
        controller.h
)

target_link_libraries(${target}
        PRIVATE
        maze_model
        cave_model
)

include_directories(.)
target_include_directories(${target} PRIVATE ..)