#pragma once
#include "class.h"
class Counter
{
private:
	int num;
public:
	Counter();
	Counter(int num);
	void increase_count();
	void decrase_count();
	int get_count();
};