#pragma once
#include "rectangle.h"
#ifndef LIB_EXPORTS
#define FIGLIB_API __declspec(dllexport)
#else
#define FIGLIB_API __declspec(dllimport)
#endif // FIGLIB_EXPORTS

class Sqare : public Rectangle
{
public:
	FIGLIB_API Sqare(int a);

};