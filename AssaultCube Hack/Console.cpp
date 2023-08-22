#include "pch.h"
#include "Console.h"

Console::Console(Config* config) noexcept {
	this->config = config;
	this->isAllocatedConsole = AllocConsole();
	if (freopen_s(&f, "CONOUT$", "w", stdout) != 0) {
		this->Destroy();
		MessageBox(nullptr, L"Error in Console::Console", L"Error", MB_OK);
	}
}

void Console::Destroy() noexcept {
	if (this->isAllocatedConsole)
		FreeConsole();

	if (this->f != nullptr)
		fclose(this->f);

	this->f = nullptr;
	this->isAllocatedConsole = false;
	this->config = nullptr;
}

void Console::PrintHackStatus() const noexcept {
	std::cout << "AssaultCube HACK [EXIT:INSERT]" << std::endl;
	std::cout << "One Shot [" << (this->config->oneShotIsActive ? "x]" : "]") << std::endl;
}

void Console::DebugAddr(const char* TAG, DWORD addr)const noexcept {
	std::cout << "DEBUG(" << TAG << "): 0x" << std::hex << addr << ")" << std::dec << std::endl;
}