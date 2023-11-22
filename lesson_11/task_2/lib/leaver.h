#pragma once
#include <iostream>
#ifndef LIB_EXPORTS
#define LEAVERLIB __declspec(dllexport)
#else
#define LEAVERLIB __declspec(dllimport)
#endif

class Leaver
{
public:
	LEAVERLIB void leave(std::string name);
};