set(target controller)

add_library(${target}
        SHARED
        controller.cc
        controller.h
)
include_directories(.)