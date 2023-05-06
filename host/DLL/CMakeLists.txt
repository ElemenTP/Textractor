# The dll isn't used by Textractor itself, but is here for other people that want to build projects on top of Textractor
add_library(Textractor SHARED dll.cpp dll.h)
target_precompile_headers(Textractor REUSE_FROM pch)
target_link_libraries(Textractor host)
