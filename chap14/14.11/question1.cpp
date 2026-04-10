#include <iostream>
#include <string>

class Ball
{
    std::string m_color;
    double m_radius;
public: 
    Ball(std::string_view color, double radius)
    :m_color{color}
    ,m_radius{radius}
    {}

    std::string& getColor()
    {
        return m_color;
    }

    double getRadius()
    {
        return m_radius;
    }
    
};

void print(Ball& ball)
    {
        std::cout <<"Ball (" << ball.getColor() << ", " << ball.getRadius() << ")\n";
    }
int main()
{
	Ball blue { "blue", 10.0 };
	print(blue);

	Ball red { "red", 12.0 };
	print(red);

	return 0;
}