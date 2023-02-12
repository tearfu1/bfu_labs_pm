#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <ctime>


class AnimatedText {
private:
    std::string text;
    size_t duration;
public:
    AnimatedText(const std::string& newText, const int& newDuration) {
        text = newText;
        duration = newDuration;
    }
    std::string getText(int currTime) {
        int time = currTime % (duration + 1);
        std::string tempText = text.substr(0, text.length() * time / duration);
        return tempText;
    }
};

int main(){
    AnimatedText ani = AnimatedText("Hello, world!", 3);
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    
    sf::Text text;
    sf::Font font;
    font.loadFromFile("Montserrat-Regular.ttf");
    text.setFont(font);
    text.setCharacterSize(20);
    text.setColor(sf::Color::White);

    
    float currTime;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        currTime = std::clock();
        text.setPosition(0,0);
        text.setString(ani.getText(currTime / 1000 + 1));
        
        window.clear();
        window.draw(text);
        window.display();
    }

    return 0;
}
