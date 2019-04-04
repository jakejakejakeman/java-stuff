#pragma once
#include <SFML/Graphics.hpp>

class Object
{
    sf::Sprite sprite;
    sf::Texture texture;
public:
    Object(const char*imageName);
    Object();
    const sf::Sprite &GetSprite() const;
    void SetPosition(float x, float y);
};