#include "robot_simulator.h"


	 
	Robot::Robot(std::pair<int, int> p, Bearing d)
		:
		pos(p),
		direction( d )
	{
		reset();
	}

	void Robot::advance()
	{
		switch (direction) {
		case(Bearing::NORTH):
			pos.second += 1 ;
			break;
		case(Bearing::EAST):
			pos.first += 1;
 			break;
		case(Bearing::SOUTH):
			pos.second -= 1;
			break;
		case(Bearing::WEST):
			pos.first += 1;
			break;
		}
	}

	void Robot::turn_right()
	{
		switch (direction) {
		case(Bearing::NORTH):
			direction = Bearing::WEST;
			break;
		case(Bearing::WEST):
			direction = Bearing::SOUTH;
			break;
		case(Bearing::SOUTH):
			direction = Bearing::EAST;
			break;
		case(Bearing::EAST):
			direction = Bearing::NORTH;
			break;
		
		}


	}

	void Robot::turn_left()
	{
		switch (direction) {
		case(Bearing::NORTH):
			direction = Bearing::EAST;
			break;
		case(Bearing::EAST):
			direction = Bearing::SOUTH;
			break;
		case(Bearing::SOUTH):
			direction = Bearing::WEST;
			break;
		case(Bearing::WEST):
			direction = Bearing::NORTH;
			break;
		}
	}

	void Robot::execute_sequence(std::string sequence)
	{
		for (auto a : sequence) {


			switch (a) {
			case('A'):
				advance();
				break;
			case('L'):
				turn_left();
				break;
			case('R'):
				turn_right();
				break;
			}
		}
	}

	


	std::string Robot::in_english(long long in)
	{
		

		std::vector<std::string> ones{ "","one", "two", "three", "four", "five", "six","seven", "eight", "nine" };
		std::vector<std::string> teens{ "ten", "eleven", "twelve", "thirteen","fourteen", "fifteen","sixteen", "seventeen","eighteen", "nineteen" };
		std::vector<std::string> tens{ "", "", "twenty", "thirty", "forty", "fifty","sixty", "seventy", "eighty", "ninety" };
		
		std::string answer = "";

		if (in == 0)
		{
			return "zero";
		}
		else if (in < 0)
		{
			throw std::domain_error("Your domain is in error!");
		}
		else if (in >= 1000000000000)
		{
			throw std::domain_error("Your domain is in error!");
		}
		else
		{
			if (in >= 1000000000 && in < 999999999999) {
				answer += in_english(in / 1000000000) + " billion" + ((in % 1000000000 != 0) ? " " + in_english(in % 1000000000) : "");
			}
			else if (in >= 1000000 && in < 1000000000) {
				answer += in_english(in / 1000000) + " million" + ((in % 1000000 != 0) ? " " + in_english(in % 1000000) : "");
			}
			else if (in >= 1000 && in < 1000000) {
				answer += in_english(in / 1000) + " thousand" + ((in % 1000 != 0) ? " " + in_english(in % 1000) : "");
			}
			else if (in >= 100 && in < 1000) {
				answer += in_english(in / 100) + " hundred" + ((in % 100 != 0) ? " " + in_english(in % 100) : "");
			}
			else if (in >= 20 && in < 100) {
				answer += tens.at(in / 10) + ((in % 10 != 0) ? "-" + in_english(in % 10) : "");
			}
			else if (in >= 10 && in < 20) {
				answer += teens.at(in - 10);
			}
			else if (in < 10) {
				answer += ones.at(in);
			}
			return answer;

		}

	}


	void Robot::reset()
	{
		prev_names.emplace_back(name_of_robot);
		std::string new_name = "";

		do {


			int n = rand() % 25;
			char c = (char)(n + 65);
			new_name += c;

			n = rand() % 25;
			c = (char)(n + 65);
			new_name += c;

			n = rand() % 9;
			new_name += std::to_string(n);
			n = rand() % 9;
			new_name += std::to_string(n);
			n = rand() % 9;
			new_name += std::to_string(n);
			name_of_robot = new_name;


			//check if name was alredy in use         


		} while (std::find(begin(prev_names), end(prev_names), name_of_robot) != std::end(prev_names));



	}