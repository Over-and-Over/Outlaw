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

    bool keyEventExist(sf::Keyboard::Key _code);
public:
    Frame();
    Frame(sf::String _background);
    ~Frame();

    void Clear();
    void Show(sf::RenderWindow& _window);

    void LoadData(const char* _path);


    void setKeyEvent(sf::Keyboard::Key _code, sf::String _script);
    sf::String getKeyEvent(sf::Keyboard::Key _code);




    void addScript(sf::String _script);
    std::vector <sf::String>& getScript() { return globalScript; };

    std::vector <Object>& getObjects() { return objects; };

    std::map <sf::String, Object> m_objects;


    void addObject(Object _obj);
    //void addObject(Object& _obj);
    //void addObject(Object& _obj);
    void removeObject(unsigned int _id);
    void cacheObject(Object _obj);


    void setName(sf::String _name) { name = _name; };

    sf::String getName() { return name; }
};


#endif // OUTLAW_FRAME
