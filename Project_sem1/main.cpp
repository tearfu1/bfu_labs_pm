#include<SFML/Graphics.hpp>
#include<string>
#include<Player.h>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Pong");
    
    
    Paddle paddle1(&window,1);
    Paddle paddle2(&window,2);
    Ball ball(&window);

    window.setFramerateLimit(160);
    
    sf::Clock clock;
    float time;
    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }

        window.clear();

        time = clock.getElapsedTime().asMicroseconds();
        time /= 800;
        clock.restart();

        paddle1.draw();
        paddle1.update(time);
        paddle2.draw();
        paddle2.update(time);
        ball.draw();
        ball.update(time, &paddle1, &paddle2);

        window.display();
    }
    return 0;
}