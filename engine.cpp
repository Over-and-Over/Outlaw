#include <SFML/Graphics.hpp>
#include "engine.h"
#include <iostream>

// Video init
Engine::Engine(unsigned short int _video_mode, sf::String _window_caption)
{
    if (_video_mode == 0) {
        video_mode = sf::VideoMode::getDesktopMode();
    } else
    if (_video_mode == 1) {
        video_mode = sf::VideoMode(1024, 768);
    } else
    if (_video_mode == 2) {
        video_mode = sf::VideoMode(800, 600);
    }
    window_caption = _window_caption;

    window = new sf::RenderWindow(video_mode, _window_caption/*, sf::Style::Fullscreen*/);
    //window->setVerticalSyncEnabled(true);
    window->setFramerateLimit(30);



    created = true;
    shutdownFlag = false;
    framesCount = 0;
    currentFrame = 0;
}

// Destructor
Engine::~Engine()
{
    delete window;
    frames.clear();
}

// Start engine
void Engine::Start()
{
    if (framesCount > 0)
        DrawScene();
}

void Engine::DrawScene()
{
    while (window->isOpen() && !shutdownFlag) {

        // Hook events
        Control();
        Interpret();

        window->clear();

        if (currentFrame <= framesCount)
            frames[currentFrame].Show(*window);

        window->display();
    }

    window->close();
}

// User interface process
void Engine::Control()
{
        script.clear();

        for (unsigned int i=0; i<frames[currentFrame].getScript().size(); i++) {
            script.push_back(frames[currentFrame].getScript()[i]);
        }

        sf::String temp;
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed) {
                temp = frames[currentFrame].getKeyEvent(event.key.code);
                if (temp != "")
                    script.push_back(temp);
            } else
            if (event.type == sf::Event::MouseButtonPressed) {
                for (unsigned int i=0; i<frames[currentFrame].getObjects().size(); i++) {
                    Object& temp1 = frames[currentFrame].getObjects()[i];
                    if (temp1.onClick == "") continue;
                    float w, h;
                    w = temp1.getSize().a;
                    h = temp1.getSize().b;
                    if (event.mouseButton.x > temp1.getX() && event.mouseButton.y > temp1.getY() &&
                        event.mouseButton.x < temp1.getX()+w && event.mouseButton.y < temp1.getY()+h) {
                        script.push_back(temp1.onClick);
                    }
                }
            } else
            if (event.type == sf::Event::MouseMoved) {
                for (unsigned int i=0; i<frames[currentFrame].getObjects().size(); i++) {
                    Object& temp1 = frames[currentFrame].getObjects()[i];
                    if (temp1.onMouseMove == "") continue;
                    float w, h;
                    w = temp1.getSize().a;
                    h = temp1.getSize().b;
                    if (event.mouseMove.x > temp1.getX() && event.mouseMove.y > temp1.getY() &&
                        event.mouseMove.x < temp1.getX()+w && event.mouseMove.y < temp1.getY()+h) {
                        script.push_back(temp1.onMouseMove);
                        temp1.setMouseUnder(true);
                    } else {
                        if (temp1.isMouseUnder()) {
                            script.push_back(temp1.onMouseExit);
                            temp1.setMouseUnder(false);
                        }
                    }
                }
            }
        }
}

// "Compiler"
void Engine::Interpret()
{
    for (unsigned int i=0; i<script.size(); i++) {

        if (script[i] == "move();") {
            frames[currentFrame].m_objects["player"].setXY(frames[currentFrame].m_objects["player"].getX() + 5, frames[currentFrame].m_objects["player"].getY() + 5);
        } else
        if (script[i] == "exit();") {
            shutdownFlag = true;
            break;
        } else
        if (script[i] == "trace();") {

        } else
        if (script[i] == "change();") {
            //frames[currentFrame].getObjects()[1].getSprite().setColor(sf::Color(100, 0, 0));
        } else
        if (script[i] == "return();") {
            //frames[currentFrame].getObjects()[1].getSprite().setColor(sf::Color(255, 255, 255));
        } else
        if (script[i] == "next();") {
            if (currentFrame + 1 <= framesCount - 1)
                currentFrame += 1;
        } else
        if (script[i] == "prev();") {
            if (currentFrame - 1 >= 0)
                currentFrame -= 1;
        } else
        if (script[i] == "start();") {
            currentFrame = 2;
        } else
        if (script[i] == "begin();") {
            currentFrame = 0;
        } else
        if (script[i] == "move();") {
            frames[currentFrame].m_objects["player"].setXY(frames[currentFrame].m_objects["player"].getX() + 5, frames[currentFrame].m_objects["player"].getY() + 5);
        }
    }


}
