#include <SFML/Graphics.hpp>
#include "KS.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    KinematicSolver robot(&window, 50, 100);
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        robot.Solve(40,100);
        robot.update();
        window.clear();
        robot.draw();
        window.display();
    }

    return 0;
}
