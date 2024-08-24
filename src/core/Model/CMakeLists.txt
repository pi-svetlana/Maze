set(target model)

add_library(${target}
        SHARED
        generator.cc
        generator.h
        reader.cc
        reader.h
#        maze_model.cc
#        maze_model.h
)
include_directories(.)
