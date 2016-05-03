#ifndef OUTLAW_CACHE
#define OUTLAW_CACHE

#include <map>
#include <list>

#include <SFML/Graphics.hpp>

class Cache {
    std::map <sf::String, sf::Texture&> textures;
    std::list <sf::Texture> temp;

public:
    Cache();
    ~Cache();

    void loadTexture(sf::String _name, sf::Texture& _texture);
    void createTexture(sf::String _name, sf::String _path, sf::Sprite& q);
    sf::Texture& getTexture(sf::String _name) { return textures.at(_name); }

};


#endif // OUTLAW_CACHE
