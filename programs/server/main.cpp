#include <iostream>
#include <exception>
#include <fmt/format.h>
#include <application.hpp>
#include <hello_plugin.hpp>

using namespace appbase;
using namespace server;

enum return_codes : int {
   OTHER_FAIL        = -2,
   INITIALIZE_FAIL   = -1,
   SUCCESS           = 0,
   BAD_ALLOC         = 1,
   DATABASE_DIRTY    = 2,
   FIXED_REVERSIBLE  = SUCCESS,
   EXTRACTED_GENESIS = SUCCESS,
   NODE_MANAGEMENT_SUCCESS = 5
};

int main(int argc, const char** argv)
{
    try {
        fmt::println("{}", "hello world");

        if(!app().initialize<hello_plugin>(argc, (char**)argv)) {
            const auto& opts = app().get_options();
            if( opts.count("help") || opts.count("version") || opts.count("full-version") || opts.count("print-default-config") ) {
                return SUCCESS;
            }
            return INITIALIZE_FAIL;
        }
        
        app().startup();
        app().set_thread_priority_max();
        app().exec();

    } catch (const std::exception& e) {
        fmt::println("{}", e.what());
        return OTHER_FAIL;
    } catch( ... ) {
        fmt::println("unknown exception");
        return OTHER_FAIL;
    }

    return SUCCESS;
}
