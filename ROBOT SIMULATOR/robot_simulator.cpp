#include "robot_simulator.h"


	 
	Robot::Robot(std::pair<int, int> p, Bearing d)
		:
		pos(p),
		direction( d )
	{
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

	
