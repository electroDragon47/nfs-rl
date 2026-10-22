#include <SFML/Graphics.hpp>
#include "car.h"

int main()
{
    sf::RenderWindow window(
        sf::VideoMode({800, 600}),
        "2D Car Simulation"
    );

    window.setFramerateLimit(60);

    // Grass/background
    sf::RectangleShape background({800.f, 600.f});
    background.setFillColor(sf::Color(45, 120, 55));

    // Simple rectangular track
    sf::RectangleShape track({600.f, 400.f});
    track.setOrigin({300.f, 200.f});
    track.setPosition({400.f, 300.f});
    track.setFillColor(sf::Color(65, 65, 65));

    // Inner grass island
    sf::RectangleShape island({300.f, 180.f});
    island.setOrigin({150.f, 90.f});
    island.setPosition({400.f, 300.f});
    island.setFillColor(sf::Color(45, 120, 55));

    // Car
    Car bmw;

    sf::Clock clock;

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        float dt = clock.restart().asSeconds();

        // Prevent a huge physics step if the window stalls
        dt = std::min(dt, 0.033f);

        bmw.update(dt);

        window.clear();

        window.draw(background);
        window.draw(track);
        window.draw(island);
        window.draw(bmw.shape);

        window.display();
    }
}