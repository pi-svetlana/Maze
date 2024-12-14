set(target cave_model)

add_library(${target}
        SHARED
        cave_model.cc
        cave_model.h
        cave_generator.cc
        cave_generator.h
        cave_reader.cc
        cave_reader.h
        cave_writer.cc
        cave_writer.h
        cave_creator.cc
        cave_creator.h
)

target_link_libraries(${target}
        PRIVATE
        utils
)

include_directories(.)
