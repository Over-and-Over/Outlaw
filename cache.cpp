#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>

#include "cache.h"

Cache::Cache()
{

}

Cache::~Cache()
{
    textures.clear();
}

void Cache::loadTexture(sf::String _name, sf::Texture& _texture)
{
    //temp.push_back(_texture);
    //temp.back().loadFromFile(_path);

    //q.setTexture(temp.back());
    //std::list<sf::Texture>::iterator it = temp.end();
    //it->loadFromFile(_path);
    std::cout << "in cache origin: "  << &_texture << std::endl;
    //std::cout << "in cache list: "  << &temp.back() << std::endl;
    textures.insert(std::pair<sf::String, sf::Texture&>(_name, _texture/*[temp.size()-1])*/));
    std::cout << "in cache map: "  << &textures.at(_name) << std::endl;
}

void Cache::createTexture(sf::String _name, sf::String _path, sf::Sprite& q)
{

    temp.push_back(sf::Texture());
    temp.back().loadFromFile(_path);

    //q.setTexture(temp.back());
    //std::list<sf::Texture>::iterator it = temp.end();
    //it->loadFromFile(_path);

    std::cout << "in cache list: "  << &temp.back() << std::endl;
    textures.insert(std::pair<sf::String, sf::Texture&>(_name, temp.back()/*[temp.size()-1])*/));
    std::cout << "in cache map: "  << &textures.at(_name) << std::endl;
}
