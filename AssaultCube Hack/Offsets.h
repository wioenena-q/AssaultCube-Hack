#pragma once
#include <cstddef>

namespace Offsets {
	namespace entity {
		constexpr ::std::ptrdiff_t dwBase = 0x195404;
		constexpr ::std::ptrdiff_t dwEntityList = 0x18AC04;
		constexpr ::std::ptrdiff_t mHealth = 0xEC;
	}

	namespace global_functions {
		constexpr ::std::ptrdiff_t dwGamePrint = 0xDAD50;
	}
}
