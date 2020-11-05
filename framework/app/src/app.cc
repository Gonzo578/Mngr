#include "app.h"						// Include own header first as it needs to compile in isolation
#include <boost/program_options.hpp> 	// Include boost::program_options in order to parse cmd line
#include <filesystem>					// include filesystem support
#include <iostream>

using namespace boost::program_options;
namespace fs = std::filesystem;

namespace framework {

Application::Application(void) {
	name_ = std::string{};
}

void Application::parseCmdLineOptions(int argc, const char *argv[]) {
	try {
		// Build command line options
		options_description desc{"Command Line Options"};
		desc.add_options()
	    		("help,h", "Help screen")
				("name,n", value<std::string>()->default_value(std::string{"MyApp"}), "Name of the application")
				("root,r", value<std::string>()->default_value(std::string{"root"}), "Path to the root node")
				("node,e", value<std::string>()->default_value(std::string{"ECU"}), "ECU node name");

	    variables_map vm;
	    store(parse_command_line(argc, argv, desc), vm);
	    notify(vm);

	    if (vm.count("help"))
	    	std::cout << desc << '\n';
	    if (vm.count("name"))
	    	name_ = vm["name"].as<std::string>();
	    if (vm.count("root"))
	    	rootNodePath_ = vm["root"].as<std::string>();
	    if (vm.count("node"))
	    	nodeName_ = vm["node"].as<std::string>();

	  }
	  catch (const error &ex) {
		  std::cerr << ex.what() << '\n';
	  }
}

void Application::run(void) {
	buildDeviceTree();
}

std::string Application::getAppName(void) {
	return name_;
}

std::string Application::getRootNodePath(void) {
	return rootNodePath_;
}

std::string Application::getNodeName(void) {
	return nodeName_;
}


void Application::buildDeviceTree(void) {
	if(isDeviceTreeRootNodeCreated() != false) {
		// root node already exists ==> continue building dev tree within root node
	} else {
		createDeviceTreeRootNode();
	}

}

bool Application::isDeviceTreeRootNodeCreated(void) {
	if(fs::exists(rootNodePath_)) {
		return true;
	} else {
		return false;
	}
}

void Application::createDeviceTreeRootNode(void) {
	fs::create_directories(rootNodePath_);
}


} // namespace Framework
