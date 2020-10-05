#include <boost/program_options.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <thread>
#include <chrono>

using namespace boost::program_options;

void to_cout(const std::vector<int> &v) {
  std::copy(v.begin(), v.end(), std::ostream_iterator<int>{
    std::cout, "\n"});
}

int main(int argc, const char *argv[])
{
	int tick;
  try
  {
    options_description generalOptions{"Options"};
    generalOptions.add_options()
      ("help,h", "Help screen")
	  ("nodes,n", value<std::vector<int>>()->multitoken()->composing(), "List of node addresses")
	  ("config", value<std::string>(), "Config file")
	  ("tick_s,t", value<int>(&tick)->default_value(1), "Mainloop tick in [s]");

    options_description fileOptions{"File"};
    fileOptions.add_options()
    	("comspeed", value<int>(), "Communication speed");

    variables_map vm;
    store(parse_command_line(argc, argv, generalOptions), vm);
    if (vm.count("config")) {
    	std::ifstream ifs{vm["config"].as<std::string>().c_str()};
        if (ifs)
        	store(parse_config_file(ifs, fileOptions), vm);
    }

    notify(vm);

    if (vm.count("help")){
    	std::cout << generalOptions << '\n';
    	return 0;
    }

    if(vm.count("nodes")) {
    	to_cout(vm["nodes"].as<std::vector<int>>());
    }

    if(vm.count("comspeed")) {
    	std::cout << "Communication speed: " << vm["comspeed"].as<int>() << '\n';
    }

    while(1) {
    	std::cout << "tick" << '\n';
    	std::this_thread::sleep_for(std::chrono::seconds(tick));
    }

  }
  catch (const error &ex)
  {
    std::cerr << ex.what() << '\n';
  }
}
