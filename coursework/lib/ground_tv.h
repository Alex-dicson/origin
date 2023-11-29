#pragma once
#include "tv.h"
#include "macros.h"
using namespace std;



//Создаем дочерний класс наземных транспортных средств, родитель класс Vehicle
class Ground : public Vehicle
{
protected:
	int _driving_time;		//время движения до отдыха
	int _speed;				// скорость	

public:
	LIBTV_API Ground();
	LIBTV_API double calc(int distance) override;
};