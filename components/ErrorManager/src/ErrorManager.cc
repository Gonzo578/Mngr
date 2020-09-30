#include "ErrorManager.h"
#include <iostream>

using namespace std;

namespace ErrorManager {

ErrorManager::ErrorManager() {

}

int ErrorManager::PrintHelloErrorManager(void) {
	cout << "Hello Error Manager" << endl;
	return 1;
}

}
