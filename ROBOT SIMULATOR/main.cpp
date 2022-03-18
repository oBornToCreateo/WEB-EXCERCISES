
#include "robot_simulator.h"
#include <unordered_set>
#include <assert.h>


bool validate_name(const std::string& name)
{
    if (name.length() != 5)
        return false;
    return std::isupper(name[0]) && std::isupper(name[1]) && std::isdigit(name[2])
        && std::isdigit(name[3]) && std::isdigit(name[4]);
}



int main()
{
	/**/
	try {
	Robot robot;
	long long ch;

	std::cin >> ch; std::cout << "\n";

	std::cout << robot.in_english(ch) << "\n";


	
	std::unordered_set<std::string> names;
	names.insert(robot.name());
	for (int i = 0; i < 1000; ++i) {
		robot.reset();
		assert(names.count(robot.name()) == 0);
		assert(validate_name(robot.name()));
		names.insert(robot.name());
		std::cout << robot.name() << "\n";
	}

	}




		catch (const std::exception& ex)
	{
		std::cout<<ex.what();
	}
};
