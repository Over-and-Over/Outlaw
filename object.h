#ifndef OUTLAW_OBJECT
#define OUTLAW_OBJECT

#include <SFML/Graphics.hpp>


class Object: /*public sf::Drawable,*/ public sf::Sprite {

    struct iPair {
        float a, b; // a = x or width, b = y or height
    };

    sf::Texture texture;
    sf::String name;



    float x, y, width, height, rotation;
    bool visible, mouseUnder;

    void refreshSprite();


    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const {;};
public:
    Object();
    Object(const Object& _obj);
    Object(sf::String _name);
    Object(sf::String _name, float _x, float _y, bool _visible);
    Object(sf::String _name, float _x, float _y, bool _visible, sf::Texture& _texture);
    ~Object();


    //Actions
    sf::String onClick;
    sf::String onMouseMove;
    sf::String onMouseExit;

    // Graphics
    //sf::Sprite& getSprite() { return sprite; };
    sf::Texture& getTexture() { return texture; };

    //
    void refreshProperty();
    void setSize(float _width, float _height);
    void setScale(float _xfactor, float _yfactor);
    void setX(float _x);
    void setY(float _y);
    void setXY(float _x, float _y);
    void setMouseUnder(bool _state) { mouseUnder = _state; }
    void setName(sf::String _name) { name = _name; }
    void setTexture(sf::Texture& _texture) { /*sprite.setTexture(_texture);*/ }

    float getWidth();
    float getHeight();
    iPair getSize();
    float getX() { return x; };
    float getY() { return y; };
    bool isVisible() { return visible; };
    bool isMouseUnder() { return mouseUnder; }
    sf::String getName() { return name; }

};


#endif // OUTLAW_OBJECT
