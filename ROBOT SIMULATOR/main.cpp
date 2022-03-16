#include "say.h"
#include "robot_simulator.h"



int main()
{
	try {

	long long ch;

	std::cin >> ch; std::cout << "\n";

	std::cout << in_english(ch) << "\n";

	}
	catch (const std::exception& ex)
	{
		std::cout<<ex.what();
	}

};