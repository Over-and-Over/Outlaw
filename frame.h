#ifndef OUTLAW_FRAME
#define OUTLAW_FRAME

#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>
#include "object.h"

class Frame {
    std::vector <Object> objects;
    std::map <sf::Keyboard::Key, sf::String> keyScripts;
    std::vector <sf::String> globalScript;

    sf::RenderWindow* window;
    sf::String background;

    sf::String name;
    sf::String onClick, onMouseMove;

    void DrawScene();
public:
    Frame();
    Frame(sf::String _background);
    ~Frame();

    sf::Sprite my;
    sf::Texture txt;

    void Clear();
    void Show(sf::RenderWindow* _window);
    void LoadData(const char* _path);

    void setKeyEvent(sf::Keyboard::Key _code, sf::String _script);
    void setName(sf::String _name) { name = _name; };
    void addScript(sf::String _script);
    void addObject(Object _obj);
    void removeObject(unsigned int _id);
    void cacheObject(Object _obj);

    std::vector <sf::String>& getScript() { return globalScript; };
    std::vector <Object>& getObjects() { return objects; };
    std::map <sf::String, Object> m_objects;
    bool keyEventExist(sf::Keyboard::Key _code);
    sf::String getKeyEvent(sf::Keyboard::Key _code);
    sf::String getName() { return name; }
};


#endif // OUTLAW_FRAME
