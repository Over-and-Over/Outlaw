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
    txt.loadFromFile("gfx\\GUI\\start.jpg");
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
    keyScripts.clear();
    globalScript.clear();
    background = "";
}

void Frame::removeObject(unsigned int _id)
{
   if (_id < objects.size()) {
        objects.erase(objects.begin() + _id);
   }
}


void Frame::Show(sf::RenderWindow* _window)
{
    window = _window;
    DrawScene();
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
        //std::cout << "in frame 1: " << objects[i].texture << std::endl;
        //std::cout << "in frame 2: " << objects[i].sprite.getTexture()->getSize().x << std::endl;
        //t = *objects[i].sprite.getTexture();
        //objects[i].sprite.setTexture(*qqq);
        window->draw(*objects[i]);
        //objects[i].testing(ptr);
    }
    //my.setTexture(txt);
    //window->draw(my);

    /*sf::Texture t;
    t.loadFromFile("gfx\\GUI\\logo.jpg");
    Object logo = Object("", 165, 30, t);
    logo.setScale(1.1, 1.1);
    logo.sprite.setTexture(t);
    window->draw(logo.sprite);*/

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
    char t;
    tmap >> width;
    tmap >> height;
    unsigned short int psize = 32;

    for (unsigned j=0; j<height; j++) {
        for (unsigned i=0; i<width; i++) {
            tmap >> t;
        }
    }
    tmap.close();
}

void Frame::addObject(Object _obj)
{
    objects.push_back(_obj);
}
void Frame::cacheObject(Object _obj)
{
    m_objects[_obj.getName()] = Object(_obj);
}


void Frame::addScript(sf::String _script)
{
    globalScript.push_back(_script);
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
