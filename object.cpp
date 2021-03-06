#include <iostream>
#include <SFML/Graphics.hpp>
#include "object.h"

Object::Object()
{
    sprite.setPosition(0, 0);

    name = "object";

    rotation = 0;

    visible = true;
    mouseUnder = false;

    onClick = "";
    onMouseMove = "";
    onMouseExit = "";
}

Object::Object(const Object& _obj)
{
    sprite = sf::Sprite(_obj.sprite);
    std::cout << "in obj copy: " << sprite.getTexture() << std::endl;

    name = _obj.name;

    rotation = _obj.rotation;
    visible = _obj.visible;
    mouseUnder = _obj.mouseUnder;

    onClick = _obj.onClick;
    onMouseMove = _obj.onMouseMove;
    onMouseExit = _obj.onMouseExit;

}

Object::Object(sf::String _name, float _x, float _y)
{
    sprite.setPosition(_x, _y);

    name = _name;

    rotation = 0;
    visible = true;
    mouseUnder = false;

    onClick = "";
    onMouseMove = "";
    onMouseExit = "";
}

Object::Object(sf::String _name, float _x, float _y, sf::Texture* _texture)
{
    std::cout << "in obj origin texture: " << _texture << std::endl;

    sprite.setPosition(_x, _y);
    sprite.setTexture(*_texture);

    name = _name;

    rotation = 0;
    visible = true;
    mouseUnder = false;

    onClick = "";
    onMouseMove = "";
    onMouseExit = "";
}

Object::~Object()
{
}

void Object::setSize(float _width, float _height)
{
    sprite.setScale(_width/getSize().x, _height/getSize().y);
}
void Object::setScale(float _xfactor, float _yfactor)
{
    sprite.setScale(_xfactor, _yfactor);
}
sf::Vector2f Object::getSize()
{
    sf::FloatRect rect = sprite.getGlobalBounds();
    return sf::Vector2f(rect.width, rect.height);
}

