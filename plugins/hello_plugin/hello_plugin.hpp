#pragma once
#include <application.hpp>

namespace server {

using namespace appbase;

/**
 *  This is a template plugin, intended to serve as a starting point for making new plugins
 */
class hello_plugin : public appbase::plugin<hello_plugin> {
public:
   hello_plugin();
   virtual ~hello_plugin();
 
   APPBASE_PLUGIN_REQUIRES()
   virtual void set_program_options(options_description&, options_description& cfg) override;
 
   void plugin_initialize(const variables_map& options);
   void plugin_startup();
   void plugin_shutdown();

private:
   std::unique_ptr<class hello_plugin_impl> my;
};

}
