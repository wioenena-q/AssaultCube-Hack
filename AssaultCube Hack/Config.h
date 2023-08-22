#pragma once
class Config
{

public:
	DWORD baseAddr;
	bool oneShotIsActive = false;
	Config(DWORD baseAddr) noexcept;
	~Config() noexcept = default;
};