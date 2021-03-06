#include <boost/program_options.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <thread>
#include <chrono>
#include <sys/un.h>
#include <sys/socket.h>

using namespace boost::program_options;

#define BUF_SIZE	1024
#define SOCK_PATH	"dev/socket"

void to_cout(const std::vector<int> &v) {
  std::copy(v.begin(), v.end(), std::ostream_iterator<int>{
    std::cout});
}

int main(int argc, const char *argv[])
{
	int tick;

	struct sockaddr_un addr;
	int sfd, cfd;
	ssize_t numRead;
	char buf[BUF_SIZE];
	std::string DevicePath;

	try
	{
		options_description generalOptions{"Options"};
		generalOptions.add_options()
    		  ("help,h", "Help screen")
			  ("nodes,n", value<std::vector<int>>()->multitoken()->composing(), "List of node addresses")
			  ("update,u", "Do update")
			  ("inventory,i", "Do inventory")
			  ("config,c", value<std::string>(), "Config file")
			  ("devpath,p", value<std::string>(), "Device path")
			  ("tick_s,t", value<int>(&tick)->default_value(1), "Mainloop tick in [s]");

		options_description fileOptions{"File"};
		fileOptions.add_options()
    			("comspeed", value<int>()->default_value(9600), "Communication speed");

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

		// update and inventory exclude each other
		if (vm.count("update")){
			std::cout << "Do update" << '\n';
			return 0;
		} else if (vm.count("inventory")){
			std::cout << "Do inventory" << '\n';
			return 0;
		}

		if(vm.count("comspeed")) {
			std::cout << "Communication speed: " << vm["comspeed"].as<int>() << '\n';
		}

		if(vm.count("devpath")) {
			std::cout << "Device Path: " << vm["devpath"].as<std::string>() << '\n';
			std::cout << argv[1] << '\n';
		}
	}
	catch (const error &ex)
	{
		std::cerr << ex.what() << '\n';
	}

	sfd = socket(AF_UNIX, SOCK_STREAM,0);
	if(sfd == -1) {
		std::cout << "Socket creation failed" << '\n';
		return 0;
	}

	if((remove(SOCK_PATH) == -1) && errno != ENOENT) {
		std::cout << "removing existing socket failed" << '\n';
		return 0;
	}

	memset(&addr, 0, sizeof(struct sockaddr_un));
	addr.sun_family = AF_UNIX;
	strncpy(addr.sun_path, SOCK_PATH, sizeof(SOCK_PATH) - 1);

	if(bind(sfd, (struct sockaddr *) &addr, sizeof(addr.sun_path) - 1) == -1) {
		std::cout << "Bind failed" << '\n';
		return 0;
	}

	if(listen(sfd, 5) == -1) {
		std::cout << "Listen failed" << '\n';
		return 0;
	}

	while(1) {
		cfd = accept(sfd, NULL, NULL);
		if(cfd == -1) {
			std::cout << "accept failed" << '\n';
			return 0;
		}

		numRead = recv (cfd, buf, BUF_SIZE-1, 0);
		if( numRead > 0) {
			std::cout << "Bytes read: " << numRead << '\n';
			buf[numRead] = '\0';
		}

		std::cout << buf << '\n';

		//std::cout << "tick" << '\n';
		//std::this_thread::sleep_for(std::chrono::seconds(tick));
	}
}
