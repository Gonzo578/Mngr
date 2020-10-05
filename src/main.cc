#include <boost/program_options.hpp>
#include <iostream>
#include <string>
#include <thread>
#include <chrono>

using namespace boost::program_options;

void on_age(int age)
{
  std::cout << "On age: " << age << '\n';
}

void on_Name(std::string Name)
{
  std::cout << "On name: " << Name << '\n';
}

int main(int argc, const char *argv[])
{
	int tick;
  try
  {
    options_description desc{"Options"};
    desc.add_options()
      ("help,h", "Help screen")
      ("pi", value<float>()->default_value(3.14f), "Pi")
      ("age", value<int>()->notifier(on_age), "Age")
	  ("name", value<std::string>()->notifier(on_Name), "Name")
	  ("tick_s,t", value<int>(&tick)->default_value(1), "Mainloop tick in [s]");

    variables_map vm;
    store(parse_command_line(argc, argv, desc), vm);
    notify(vm);

    if (vm.count("help")){
    	std::cout << desc << '\n';
    	return 0;
    }
    else if (vm.count("name") && vm.count("age"))
      std::cout << "Hallo " << vm["name"].as<std::string>() << ", wie geht es Dir?" << " Du bis " <<vm["age"].as<int>() << " Jahre alt." << '\n';
    else if (vm.count("age"))
      std::cout << "Age: " << vm["age"].as<int>() << '\n';
    else if (vm.count("pi"))
      std::cout << "Pi: " << vm["pi"].as<float>() << '\n';

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
