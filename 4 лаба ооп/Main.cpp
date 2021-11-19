#include<iostream>
#include "Triad.h"
#include "Time.h"

void menu();


int main()
{
	
	std::cout << "Please, eneter first 3 numbers: ";
	Triad FirstTriad;
	std::cin >> FirstTriad;


	std::cout << "Please, eneter second 3 numbers: ";
	Triad SecondTriad;
	std::cin >> SecondTriad;

	std::string example;
	std::cout << "\nPlease, enter first time: HH:MM:SS ";
	std::cin >> example;
	Time FirstTime(example);

	std::cout << "\nPlease, enter second time: HH, MM, SS ";
	Time SecondTime;
	std::cin >> SecondTime;

	int chose = 0;

	do 
	{
		menu();
		std::cin >> chose;

		switch (chose)
		{
		case 1:
		{
			Triad* result = FirstTriad + SecondTriad;
			std::cout << (*result);

			delete result;
			result = nullptr;
		}break;
		case 2:
		{
			Triad* dop;
			dop = FirstTime + SecondTime;
			
			Time* result = static_cast <Time*> (dop);
			result->normalize();

			std::cout << (*result);

			delete dop;
			dop = nullptr;
		}break;
		case 3:
		{
			FirstTriad.incAll();
		}break;
		case 4:
		{
			FirstTime.incAll();
			FirstTime.normalize();
		}break;
		case 5:
		{
			std::cout << FirstTriad << " " << SecondTriad;
		}break;
		case 6:
		{
			std::cout << FirstTime << " " << SecondTime;
		}break;
		case 7:
		{
			int first, second;

			std::cout << "\nEnter value minutes:";
			std::cin >> first;
			std::cout << "\nEnter value seconds:";
			std::cin >> second;

			FirstTime.incMinuteAndSecond(first, second);
		}break;
		case 8:
		{
			if (FirstTriad == SecondTriad) std::cout << "\nTriad is equal";
			else
				if (FirstTriad > SecondTriad) std::cout << "\nFirst triad is bigger then first";
				else std::cout << "\nFirst triad is smaller then first";
		}break;
		case 9:
		{
			if (FirstTime == SecondTime) std::cout << "\nTime is equal";
			else
				if (FirstTime > SecondTime) std::cout << "\nFirst time is bigger then first";
				else std::cout<< "\nFirst time is smaller then first";
		}
		}
	} while (chose != 10);

	return 0;
}

void menu()
{
	std::cout << "\n----------------------------------";
	std::cout << "\n1)Triad+Triad";
	std::cout << "\n2)Time+Time";
	std::cout << "\n3)Inc first Triad";
	std::cout << "\n4)Inc first Time";
	std::cout << "\n5)Out all Triad";
	std::cout << "\n6)Out all Time";
	std::cout << "\n7)Increase minute and second on N in first time";
	std::cout << "\n8)Compare the triad";
	std::cout << "\n9)Compare the time";
	std::cout << "\n10) End of programm";
	std::cout << "\n----------------------------------\n";
}
