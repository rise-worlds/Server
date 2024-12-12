#include <hello_plugin.hpp>
#include <fmt/format.h>

namespace server {
   static appbase::abstract_plugin& _hello_plugin = app().register_plugin<hello_plugin>();

class hello_plugin_impl {
public:
    void output() {
        fmt::println("hello_plugin_impl::output");
    }
};

hello_plugin::hello_plugin():my(new hello_plugin_impl()){}
hello_plugin::~hello_plugin(){}

void hello_plugin::set_program_options(options_description&, options_description& cfg) {
   cfg.add_options()
         ("option-name", bpo::value<string>()->default_value("default value"),
          "Option Description")
         ;
}

void hello_plugin::plugin_initialize(const variables_map& options) {
    fmt::println("hello_plugin::plugin_initialize");
    my->output();
}

void hello_plugin::plugin_startup() {
   // Make the magic happen
    fmt::println("hello_plugin::plugin_startup");
}

void hello_plugin::plugin_shutdown() {
   // OK, that's enough magic
    fmt::println("hello_plugin::plugin_shutdown");
}

}
