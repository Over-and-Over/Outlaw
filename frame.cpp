#include <iostream>
#include <fstream>
#include <vector>
#include <map>

#include <SFML/Graphics.hpp>
#include "frame.h"

Frame::Frame(sf::String _background)
{
    background = _background;
    onClick ="";
    onMouseMove = "";
}

Frame::Frame()
{
    background ="";
    onClick ="";
    onMouseMove = "";
}

Frame::~Frame()
{
    objects.clear();
    keyScripts.clear();
    globalScript.clear();
}
void Frame::Clear()
{
    objects.clear();
    background = "";
}

void Frame::removeObject(unsigned int _id)
{
   if (_id < objects.size()) {
        objects.erase(objects.begin() + _id);
   }
}


void Frame::Show(sf::RenderWindow& _window)
{
    window = &_window;
    DrawScene();
}

void Frame::addScript(sf::String _script)
{
    globalScript.push_back(_script);
}

void Frame::DrawScene()
{
    sf::Sprite temp;
    sf::Texture t;

    if (background != "") {
        t.loadFromFile(background);
        t.setRepeated(true);
        sf::RectangleShape rectangle(sf::Vector2f((window->getSize()).x, (window->getSize()).y));
        rectangle.setTexture(&t);
        window->draw(rectangle);
    }

    for (unsigned int i=0; i<objects.size(); i++) {
        //window->draw(objects[i].getSprite());
    }

    for (std::map<sf::String, Object>::iterator it=m_objects.begin(); it!=m_objects.end(); ++it) {
        //temp = (it->second).getSprite();
        //std::cout << (std::string)(it->first) << " -- " << (std::string)(it->second).getTexturePath() << std::endl;
        //temp.setTexture(t);
        //window->draw(temp);
    }

}

void Frame::LoadData(const char* _path)
{
    std::ifstream tmap;
    tmap.open(_path);

    int width, height;
    tmap >> width;
    tmap >> height;
    unsigned short int psize = 32;

    int i = 0, j = 0;
    char t;
    sf::String tmp_texture;
    for (j=0; j<height; j++) {
        for (i=0; i<width; i++) {
            tmap >> t;
            /*if (t == '.') {
                tmp_texture = "gfx\\objects\\sand1.jpg";
            } else
            if (t == 'B') {
                tmp_texture = "gfx\\objects\\wall1.jpg";
            } else
            if (t == 'b') {
                tmp_texture = "gfx\\objects\\box1.png";
            } else
            if (t == 't') {
                tmp_texture = "gfx\\objects\\box2.png";
            }*/
            addObject(Object("block", i*psize, j*psize, true));
        }
    }
    tmap.close();
}

void Frame::addObject(Object _obj)
{
    //if (objects.count(_obj.getName()) = 0)
    objects.push_back(_obj);

}

void Frame::cacheObject(Object _obj)
{
    m_objects[_obj.getName()] = Object(_obj);
}


void Frame::setKeyEvent(sf::Keyboard::Key _code, sf::String _script)
{
    if (!keyEventExist(_code))
        keyScripts.insert(std::pair<sf::Keyboard::Key, sf::String>(_code, _script));
    else
        keyScripts[_code] = _script;
}
bool Frame::keyEventExist(sf::Keyboard::Key _code)
{
    if(keyScripts.count(_code) > 0)
        return true;
    else
        return false;
}
sf::String Frame::getKeyEvent(sf::Keyboard::Key _code)
{
    if (keyEventExist(_code))
        return keyScripts[_code];
    else
        return "";
}
