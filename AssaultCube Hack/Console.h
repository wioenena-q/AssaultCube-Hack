#pragma once
#include "Config.h"

class Console
{
private:
	Config* config = nullptr;
	bool isAllocatedConsole = false;
	FILE* f = nullptr;
public:
	Console(Config* config) noexcept;
	~Console() noexcept = default;
	void Destroy() noexcept;
	void PrintHackStatus() const noexcept;
	void DebugAddr(const char* TAG, DWORD addr) const noexcept;
};

