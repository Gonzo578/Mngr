#pragma once			// prevent multiple inclusions

#include <string>

/**
 * 	\brief	Application framework namespace
 * */
namespace framework {

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
	 * 			This method runs git the applications event loop and typically never returns
	 * */
	void run(void);

	/**
	 * 	\brief Function returns the name of the application
	 * */
	std::string getAppName(void);

	/**
	 * 	\brief Function returns the name of the application
	 * */
	std::string getRootNodePath(void);

	/**
	 * 	\brief Function returns the name of the ECU node
	 * */
	std::string getNodeName(void);

private:
	std::string	name_;			//< Application name
	std::string	rootNodePath_;	//< Path of the application root node
	std::string	nodeName_;		//< ECU node name

	void buildDeviceTree(void);
	bool isDeviceTreeRootNodeCreated(void);
	void createDeviceTreeRootNode(void);
};

} // namespace framework
