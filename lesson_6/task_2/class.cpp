#include "class.h"

Counter::Counter()
{
	this->num = 1;
}

Counter::Counter(int num)
{
	this->num = num;
}

void Counter::increase_count()
{
	this->num++;
}
void Counter::decrase_count()
{
	this->num--;
}
int Counter::get_count()
{
	return this->num;
}