#include "pch.h"
#include "Game.h"

namespace Game {
	namespace Functions {
		Types::gamePrint_t gamePrint;
		void init_all(Config* config) noexcept
		{
			gamePrint = reinterpret_cast<Types::gamePrint_t>(config->baseAddr + Offsets::global_functions::dwGamePrint);
		}
	}
}
