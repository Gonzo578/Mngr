#include "ProgramManager.h"		// first include own header ==> file needs to compile in isolation
#include <iostream>

using namespace std;

namespace ProgramManager {
	ProgramManager::ProgramManager(void) {
		AvailablePrograms.push_back("Auto");
		AvailablePrograms.push_back("Eco");
		AvailablePrograms.push_back("Super");
	}

	std::list<std::string> ProgramManager::GetAvailablePrograms(void) {
		return AvailablePrograms;
	}
}
