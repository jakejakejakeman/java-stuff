#include "Object.h"
Object::Object(){}
Object::Object(const char *imageName)
{
    texture.loadFromFile(imageName);
    sprite.setTexture(texture);
}

const sf::Sprite &Object::GetSprite() const {
    return sprite;
}
void Object::SetPosition(float x, float y)
{
    sprite.setPosition(x,y);
}
