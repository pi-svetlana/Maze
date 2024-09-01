set(target model)

add_library(${target}
        SHARED
        generator.cc
        generator.h
        reader.cc
        reader.h
        writer.cc
        writer.h
        searcher.cc
        searcher.h
        maze_model.cc
        maze_model.h
)

target_link_libraries(${target}
        PRIVATE
        utils
)

include_directories(.)
target_include_directories(${target} PRIVATE ..)
