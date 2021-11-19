#pragma once

class Triad
{
protected:
	int first;
	int second;
	int third;
public:
	Triad();
	Triad(int _first, int _second, int _third);
	Triad(const Triad& obj);
	
	void setFirst(int _first);
	void setSecond(int _second);
	void setThird(int _third);

	int getFirst();
	int getSecond();
	int getThird();

	void incFirst();
	void incSecond();
	void incThird();
	void incAll();

	Triad* operator+(Triad& obj);
	Triad* operator-(Triad& obj);

	bool operator<(const Triad& obj);
	bool operator>(const Triad& obj);
	bool operator==(const Triad& obj);

	Triad* operator=(const Triad& obj);

	friend std::ostream& operator<< (std::ostream& out, Triad& obj);
	friend std::istream& operator>> (std::istream& in, Triad& obj);
};
