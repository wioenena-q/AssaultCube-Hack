// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "Config.h"
#include "Console.h"
#include "Game.h"

DWORD WINAPI MainThread(LPVOID hModule) {
	DWORD baseAddr = reinterpret_cast<DWORD>(GetModuleHandle(L"ac_client.exe"));
	Config* config = new Config(baseAddr);
	Console console(config);

	Game::Functions::init_all(config);

#ifndef RELEASE
	console.DebugAddr("Module Base", baseAddr);
	std::cout << "All game functions loaded" << std::endl;
#endif // !RELEASE

	console.PrintHackStatus();

	while (!GetAsyncKeyState(VK_INSERT)) {
		if (GetAsyncKeyState(VK_F1) & 1) {
			config->oneShotIsActive = !config->oneShotIsActive;
			system("cls");
			console.PrintHackStatus();
			Game::Functions::gamePrint("%s:\f%s %s", "One Shot", config->oneShotIsActive ? "0" : "3", config->oneShotIsActive ? "Active" : "Deactive");
		}
	}

	console.Destroy();
	FreeLibraryAndExitThread(reinterpret_cast<HMODULE>(hModule), 0);
	return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
	if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
		HANDLE hThread = CreateThread(NULL, NULL, MainThread, hModule, NULL, NULL);
		if (hThread != NULL)
			CloseHandle(hThread);
	}
	return TRUE;
}

