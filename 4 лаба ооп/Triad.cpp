#include <iostream>
#include "Triad.h"

Triad::Triad()
{
	first = 0;
	second = 0;
	third = 0;
}

Triad::Triad(int _first, int _second, int _third)
{
	first = _first;
	second = _second;
	third = _third;
}

Triad::Triad(const Triad& obj)
{
	first = obj.first;
	second = obj.second;
	third = obj.third;
}



inline void Triad::setFirst(int _first)
{
	first = _first;
}

inline void Triad::setSecond(int _second)
{
	second = _second;
}

inline void Triad::setThird(int _third)
{
	third = _third;
}


int Triad::getFirst()
{
	return first;
}

int Triad::getSecond()
{
	return second;
}

int Triad::getThird()
{
	return third;
}



inline void Triad::incFirst()
{
	first++;
}

inline void Triad::incSecond()
{
	second++;
}

inline void Triad::incThird()
{
	third++;
}

void Triad::incAll()
{
	first++;
	second++;
	third++;
}



Triad* Triad::operator+(Triad& obj)
{
	Triad *dop = new Triad;

	dop->first = obj.getFirst()+ first;
	dop->second =second + obj.getSecond();
	dop->third =third + obj.getThird();

	return dop;
}

Triad* Triad::operator-(Triad& obj)
{
	Triad* dop = new Triad;

	dop->first = obj.getFirst() - first;
	dop->second = second - obj.getSecond();
	dop->third = third - obj.getThird();

	return dop;
}


bool Triad::operator<(const Triad& obj)
{
	return ((first < obj.first) || (first == obj.first && second < obj.second) || (first == obj.first && second == obj.second && third < obj.third));
}

bool Triad::operator>(const Triad& obj)
{
	return ((first > obj.first) || (first == obj.first && second > obj.second) || (first == obj.first && second == obj.second && third > obj.third));
}

bool Triad::operator==(const Triad& obj)
{
	return (first == obj.first && second == obj.second && third == obj.third);

}


Triad* Triad::operator=(const Triad& obj)
{
	if (this != &obj)
	{
		first = obj.first;
		second = obj.second;
		third = obj.third;
	}

	return this;
}


std::ostream& operator<<(std::ostream& out, Triad& obj)
{
	out << "\nFirst: " << obj.getFirst();
	out << "\nSecond: " << obj.getSecond();
	out << "\nThird: " << obj.getThird();

	return out;
}

std::istream& operator>>(std::istream& in, Triad& obj)
{
	int value;

	in >> value;
	obj.setFirst(value);
	in >> value;
	obj.setSecond(value);
	in >> value;
	obj.setThird(value);

	return in;
}
