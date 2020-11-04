#pragma once			// prevent multiple inclusions

#include <string>

/**
 * 	\brief The application class
 * */
class Application {
public:
	/**
	 *	\brief	CTor
	 **/
	Application();

	/**
	 * 	\brief	Command line options parser
	 * */
	void parseCmdLineOptions(int argc, const char *argv[]);

	/**
	 * 	\brief	Application run method
	 *
	 * 			This method runs the applications event loop and typically never returns
	 * */
	void run(void);

	/**
	 * 	\brief Function returns the name of the application
	 * */
	std::string getAppName(void);

private:
	std::string	name_;			//< Application name
};
