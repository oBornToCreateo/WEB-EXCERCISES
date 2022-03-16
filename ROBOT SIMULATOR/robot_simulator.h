#if !defined(ROBOT_SIMULATOR_H)
#define ROBOT_SIMULATOR_H
#include  <utility>
#include  <string>
	



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
        Robot(std::pair<int, int> p , Bearing d );
        Robot(const Robot&) = delete;
        Robot& operator=(const Robot&) = delete;
        ~Robot() = default;

        void advance();
        void turn_right();
        void turn_left();
        void execute_sequence(const std::string sequence);

        std::pair<int, int> get_position() const {return pos;};
        Bearing get_bearing() const {return direction;};
        
    private:
        std::pair<int, int> pos = { 0,0 };
        Bearing direction = Bearing::NORTH;

    };




#endif // ROBOT_SIMULATOR_H