#include <SFML/Graphics.hpp>
#include "object.h"

/*Object::std_height = 32;
Object::std_width = 32;*/

Object::Object()
{
    name = "object";

    x = 0;
    y = 0;
    width = 0;
    height = 0;
    rotation = 0;
    visible = true;
    mouseUnder = false;

    onClick = "";
    onMouseMove = "";
    onMouseExit = "";
}

Object::Object(const Object& _obj)
{
    texture = _obj.texture;
    //sprite = _obj.sprite;
    name = _obj.name;

    x = _obj.x;
    y = _obj.y;
    width = _obj.width;
    height = _obj.height;
    rotation = _obj.rotation;
    visible = _obj.visible;
    mouseUnder = _obj.mouseUnder;

    onClick = _obj.onClick;
    onMouseMove = _obj.onMouseMove;
    onMouseExit = _obj.onMouseExit;
}

Object::Object(sf::String _name)
{
    onClick = "";
    onMouseMove = "";
    onMouseExit = "";

    x = 0;
    y = 0;
    rotation = 0;
    visible = true;
    mouseUnder = false;

    name = _name;

    refreshSprite();
}

Object::Object(sf::String _name, float _x, float _y, bool _visible)
{
    onClick = "";
    onMouseMove = "";
    onMouseExit = "";

    x = _x;
    y = _y;
    rotation = 0;
    visible = _visible;
    mouseUnder = false;

    name = _name;

    refreshSprite();
}

Object::Object(sf::String _name, float _x, float _y, bool _visible, sf::Texture& _texture)
{
    //sprite.setTexture(_texture);

    onClick = "";
    onMouseMove = "";
    onMouseExit = "";

    x = _x;
    y = _y;
    rotation = 0;
    visible = _visible;
    mouseUnder = false;

    name = _name;

    refreshSprite();
}

Object::~Object()
{

}

void Object::setSize(float _width, float _height)
{
    //sprite.setScale(_width/width, _height/height);
    refreshSprite();
}

void Object::setScale(float _xfactor, float _yfactor)
{
    //sprite.setScale(_xfactor, _yfactor);
    refreshSprite();
}

void Object::setX(float _x)
{
    x = _x;
    refreshSprite();
}
void Object::setY(float _y)
{
    x = _y;
    refreshSprite();
}
void Object::setXY(float _x, float _y)
{
    x = _x;
    y = _y;
    refreshSprite();
}

void Object::refreshSprite()
{
    //sprite.setPosition(x, y);
    //sf::FloatRect rect = sprite.getGlobalBounds();
    width = rect.width;
    height = rect.height;
}

float Object::getWidth()
{
    //sf::FloatRect rect = sprite.getGlobalBounds();
    width = rect.width;
    height = rect.height;
    return width;
}

float Object::getHeight()
{
    //sf::FloatRect rect = sprite.getGlobalBounds();
    width = rect.width;
    height = rect.height;
    return height;
}

Object::iPair Object::getSize()
{
    //sf::FloatRect rect = sprite.getGlobalBounds();
    iPair temp;
    temp.a = rect.width;
    temp.b = rect.height;
    return temp;
}
