#pragma once
#include <utility>
#include <string>
#include <vector>
#include <iostream>
#include <exception>
#include <typeinfo>
#include <iostream>
#include <random>
#include <cstdlib>
#include <algorithm>
#include <iterator>



class Robot
{
public:

    enum class Bearing
    {
        NORTH,
        EAST,
        SOUTH,
        WEST
    };

    Robot() = default;
    Robot(std::pair<int, int> p, Bearing d);
    Robot(const Robot&) = delete;
    Robot& operator=(const Robot&) = delete;
    ~Robot() = default;

    int bin_to_int(std::string in);

    void reset();
    std::string name() const { return name_of_robot; };

    void advance();
    void turn_right();
    void turn_left();
    void execute_sequence(const std::string sequence);

    std::string in_english(long long in);

    std::pair<int, int> get_position() const { return pos; };
    Bearing get_bearing() const { return direction; };

private:
    std::pair<int, int> pos = { 0,0 };
    Bearing direction = Bearing::NORTH;
    std::string name_of_robot = "";
    std::vector<std::string> prev_names;
};


