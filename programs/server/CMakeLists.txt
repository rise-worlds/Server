add_executable(server main.cpp)
target_link_libraries(server PRIVATE 
    Boost::system 
    fmt::fmt-header-only
    appbase 
    hello_plugin
    )