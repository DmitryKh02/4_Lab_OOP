#include <string>
#include<cmath>
#include<iostream>
#include "Time.h"


#pragma warning(disable : 4996)


Time::Time()
{

}

Time::Time(int _hour, int _minute, int _second):Triad(_hour,_minute,_second)
{
	normalize();
}

Time::Time(std::string str)
{
	int i = 0;

	first = abs(stoi(str.substr(i, 2)));
	i += 3;

	second = abs(stoi(str.substr(i, 2)));
	i += 3;

	third = abs(stoi(str.substr(i, 2)));

	normalize();
}

Time::Time(int _second)
{
	first = _second / 3600;
	first %= 24;

	_second %= 3600;
	second = _second / 60;

	_second %= 60;
	third = _second;
}

Time::Time(double realTime)
{
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);

	first = timeinfo->tm_hour;
	second = timeinfo->tm_min;
	third = timeinfo->tm_sec;
}

Time::Time(const Time& obj)
{
	first = obj.first;
	second = obj.second;
	third = obj.third;
}

Time::Time(Triad& obj)
{
	first = obj.getFirst();
	second = obj.getSecond();
	third = obj.getThird();
}


void Time::normalize()
{
	if (third >= 60)
	{
		second += third / 60;
		third %= 60;
	}

	if (second >= 60)
	{
		first += second / 60;
		second %= 60;
	}

	if (first >= 24) first %= 24;
}


int Time::toSec()
{
	return third + 60 * (second) + 60 * 60 * (first);
}

int Time::toMin()
{
	double sec = third;
	sec /= 60;
	return second + 60 * first + (ceil(sec));
}


void Time::addSec(int s)
{
	third += s;

	normalize();
}

void Time::minusSec(int s)
{
	int sec = abs(toSec() - s);

	normalize();
}


void Time::incMinuteAndSecond(const int dopMinute, const int dopSecond)
{
	third += dopSecond;
	second += dopMinute;

	normalize();
}


Time& Time::operator=(const Time& obj)
{
	if (this != &obj)
	{ 
		first = obj.first;
		second = obj.second;
		third = obj.third;
	}
	return *this;
}

Time& Time::operator=(const std::string str)
{
	if (str == "") {
		first = 0;
		second = 0;
		third = 0;
	}
	else {
		int i = 0;
		first = stoi(str.substr(i, 2));
		i += 3;
		second = stoi(str.substr(i, 2));
		i += 3;
		third = stoi(str.substr(i, 2));
	}

	normalize();

	return *this;
}


std::ostream& operator<<(std::ostream& out,Time& obj)
{
	out << "\n" << obj.getFirst() << ":" << obj.getSecond() << ":" << obj.getThird();

	return out;
}

std::istream& operator>>(std::istream& in,Time& obj)
{
	int value;

	in >> value;
	obj.Time::setFirst(value);
	in >> value;
	obj.Time::setSecond(value);
	in >> value;
	obj.Time::setThird(value);

	obj.normalize();

	return in;
}