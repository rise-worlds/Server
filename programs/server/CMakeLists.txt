add_executable(server main.cpp)
target_link_libraries(server PRIVATE 
    Boost::system PRIVATE 
    fmt::fmt-header-only
    )