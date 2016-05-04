#ifndef OUTLAW_OBJECT
#define OUTLAW_OBJECT

#include <SFML/Graphics.hpp>

class Object: public sf::Drawable
{
    sf::String name;

    float rotation;
    bool visible, mouseUnder;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        target.draw(sprite);
    }
public:
    Object();
    Object(const Object& _obj);
    Object(sf::String _name, float _x, float _y);
    Object(sf::String _name, float _x, float _y, sf::Texture* _texture);
    ~Object();

    sf::Sprite sprite;

    //Actions
    sf::String onClick;
    sf::String onMouseMove;
    sf::String onMouseExit;

    // Interface
    void setSize(float _width, float _height);
    void setScale(float _xfactor, float _yfactor);
    void setMouseUnder(bool _state) { mouseUnder = _state; }
    void setName(sf::String _name) { name = _name; }
    void setVisible(bool _state) { visible = _state; }

    sf::String getName() { return name; }
    sf::Vector2f getSize();
    float getX() { return sprite.getPosition().x; };
    float getY() { return sprite.getPosition().y; };
    bool isVisible() { return visible; };
    bool isMouseUnder() { return mouseUnder; }
};


#endif // OUTLAW_OBJECT
