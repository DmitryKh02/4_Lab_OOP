#pragma once
#include "Triad.h"

class Time: public Triad 
{
public:
	Time();
	Time(int _hour, int _minute, int _second);
	Time(std::string str);
	Time(int second);
	Time(double realTime);
	Time(const Time& obj);
	Time(Triad& obj);

	void setFirst(int h);
	void setSecond(int m);
	void setThird(int s);

	void normalize();

	int toSec();
	int toMin();

	void addSec(int s);
	void minusSec(int s);

	void incFirst();
	void incSecond();
	void incThird();

	void incMinuteAndSecond(const int dopMinute, const int dopSecond);

	Time& operator=(const Time& obj);
	Time& operator=(const std::string str);

	friend std::ostream& operator<< (std::ostream& out, Time& obj);
	friend std::istream& operator>> (std::istream& in, Time& obj);
};
