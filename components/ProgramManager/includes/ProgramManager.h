//*************************************************************************************************
//
//*************************************************************************************************
#include <cstdint>
#include <string>
#include <list>

namespace ProgramManager {
	class ProgramManager {
	public:
		ProgramManager();
		std::list<std::string> GetAvailablePrograms();
	private:
		std::list<std::string> AvailablePrograms;
	};
}
