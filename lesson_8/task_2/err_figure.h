#pragma once
#include <iostream>
using namespace std;

class Err_Figure : public domain_error
{
public:
	Err_Figure(const char* message);
};