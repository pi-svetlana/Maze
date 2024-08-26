set(target controller)

add_library(${target}
        SHARED
        controller.cc
        controller.h
)

target_link_libraries(${target}
        PRIVATE
        model
)

include_directories(.)