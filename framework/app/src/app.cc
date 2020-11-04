#include "app.h"						// Include own header first as it needs to compile in isolation
#include <boost/program_options.hpp> 	// Include boost::program_options in order to parse cmd line
#include <iostream>

Application::Application(void) {
	name_ = std::string{"MyApp"};	//std::string{};
}

void Application::parseCmdLineOptions(int argc, const char *argv[]) {

}

void Application::run(void) {

}

std::string Application::getAppName(void) {
	return name_;
}
