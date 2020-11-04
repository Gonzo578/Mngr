#include "app.h"						// Include own header first as it needs to compile in isolation
#include <boost/program_options.hpp> 	// Include boost::program_options in order to parse cmd line
#include <iostream>

using namespace boost::program_options;

Application::Application(void) {
	name_ = std::string{};
}

void Application::parseCmdLineOptions(int argc, const char *argv[]) {
	try {
		options_description desc{"Command Line Options"};
		desc.add_options()
	    		("help,h", "Help screen")
				("name,n", value<std::string>()->default_value(std::string{"MyApp"}), "Name of the application");

	    variables_map vm;
	    store(parse_command_line(argc, argv, desc), vm);
	    notify(vm);

	    if (vm.count("help"))
	    	std::cout << desc << '\n';
	    if (vm.count("name"))
	    	name_ = vm["name"].as<std::string>();

	  }
	  catch (const error &ex) {
		  std::cerr << ex.what() << '\n';
	  }
}

void Application::run(void) {

}

std::string Application::getAppName(void) {
	return name_;
}
