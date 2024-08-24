set(target utils)

add_library(${target}
        SHARED
        utils.cc
        utils.h)

include_directories(.)