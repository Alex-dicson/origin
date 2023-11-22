#pragma once
#include <iostream>
#ifdef LIB_EXPORTS
#define FIGLIB_API __declspec(dllexport)
#else
#define FIGLIB_API __declspec(dllimport)
#endif // FIGLIB_EXPORTS

using namespace std;

class Figure
{
protected:
	string name;
public:
	FIGLIB_API Figure();
	FIGLIB_API virtual void print();

};