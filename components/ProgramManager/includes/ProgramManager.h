/**
 * @file ProgramManager.h Program Manager API
 * */
#pragma once

#include <cstdint>
#include <string>
#include <list>

namespace ProgramManager {
	/**
	 * 	@class Program Manager API
	 * */
	class ProgramManager {
	public:
		/**
		 * 	@brief	Constructor
		 * */
		ProgramManager();

		/**
		 * 	@brief Return list of available Programs
		 */
		std::list<std::string> GetAvailablePrograms();
	private:
		std::list<std::string> AvailablePrograms;
	};
}
