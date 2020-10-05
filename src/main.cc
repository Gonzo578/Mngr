#include <boost/program_options.hpp>
#include <iostream>
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
	  ("tick_s,t", value<int>(&tick)->default_value(1), "Mainloop tick in [s]");

    variables_map vm;
    store(parse_command_line(argc, argv, generalOptions), vm);
    notify(vm);

    if (vm.count("help")){
    	std::cout << generalOptions << '\n';
    	return 0;
    }

    if(vm.count("nodes")) {
    	to_cout(vm["nodes"].as<std::vector<int>>());
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
