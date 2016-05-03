#ifndef OUTLAW_ENGINE
#define OUTLAW_ENGINE

#include  <vector>
#include <SFML/Graphics.hpp>
#include "frame.h"


class Engine {
    sf::VideoMode video_mode;
    sf::RenderWindow* window;

    bool created, shutdownFlag;
    unsigned int framesCount, currentFrame;
    sf::String window_caption;

    std::vector <Frame> frames;
    std::vector <sf::String> script;

    void Control();
    void DrawScene();
    void Interpret();
public:
    Engine(unsigned short int _video_mode, sf::String _window_caption);
    ~Engine();

    sf::VideoMode getVideoMode() { return video_mode; };
    sf::String getWindowCaption() { return window_caption; };

    void addFrame(Frame _frame) { frames.push_back(_frame); framesCount++; };
    void Start();

};


#endif // OUTLAW_ENGINE
