#include "car.h"

#include <algorithm>
#include <cmath>

Car::Car()
{
    shape.setSize({40.f, 20.f});
    shape.setOrigin({20.f, 10.f});
    shape.setPosition({400.f, 300.f});
    shape.setFillColor(sf::Color::Red);
}

void Car::update(float dt)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        speed += acceleration * dt;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        speed -= acceleration * dt;

    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) &&
        !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {
        if (speed > 0.f)
            speed = std::max(0.f, speed - friction * dt);
        else if (speed < 0.f)
            speed = std::min(0.f, speed + friction * dt);
    }

    speed = std::clamp(speed, -maxSpeed * 0.4f, maxSpeed);

    float steering = 0.f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        steering -= 1.f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        steering += 1.f;

    if (std::abs(speed) > 5.f)
    {
        float direction = speed >= 0.f ? 1.f : -1.f;

        shape.rotate(sf::degrees(
            steering * steeringSpeed * dt * direction
        ));
    }

    float angle = shape.getRotation().asRadians();

    sf::Vector2f forward{
        std::cos(angle),
        std::sin(angle)
    };

    shape.move(forward * speed * dt);
}