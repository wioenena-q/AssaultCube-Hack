#pragma once
#include "Config.h"
#include "Offsets.h"

namespace Game {
	namespace Types {
		typedef void(*gamePrint_t)(const char* format, ...);
	}

	namespace Functions {
		extern Types::gamePrint_t gamePrint;
		void init_all(Config* config) noexcept;
	}
}