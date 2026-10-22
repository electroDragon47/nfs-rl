#pragma once

#include <SFML/Graphics.hpp>

class Car
{
public:
    sf::RectangleShape shape;

    float speed = 0.f;
    float acceleration = 180.f;
    float maxSpeed = 300.f;
    float steeringSpeed = 120.f;
    float friction = 100.f;

    Car(); // Declaration only

    void update(float dt);
};