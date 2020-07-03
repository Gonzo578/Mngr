#include <iostream>
#include <list>
#include <string>
#include "ProgramManager.h"

using namespace std;

int main (int argc, char** argv) {
	list<string> Programs;

	ProgramManager::ProgramManager ProgMngr;

	cout << "Hello World!" << endl;

	Programs = ProgMngr.GetAvailablePrograms();



	for (auto& ProgName : Programs) {
		cout << ProgName << endl;
	}

	return 0;
}
