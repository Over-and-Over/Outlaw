#include <iostream>

#include <SFML/Graphics.hpp>

#include "engine.h"
#include "frame.h"
#include "object.h"
#include "cache.h"

//const int width = 100, height = 100; // 100 cells

int main()
{
    Engine game = Engine(2, "Outlaw");

    Cache cache = Cache();

    //cache.createTexture("btn_exit", "gfx\\GUI\\exit.jpg");
    sf::Texture test = sf::Texture();
    test.loadFromFile("gfx\\GUI\\start.jpg");
    cache.loadTexture("btn_start", test);/*
    test = sf::Texture();
    test.loadFromFile("gfx\\GUI\\options.jpg");
    cache.loadTexture("btn_options", test);
    test = sf::Texture();
    test.loadFromFile("gfx\\GUI\\exit.jpg");
    cache.loadTexture("btn_exit", test);*/


    /* Main menu */
    Frame main_menu = Frame("gfx\\backgrounds\\background.png");
    main_menu.setName("menu");
    main_menu.setKeyEvent(sf::Keyboard::Escape, "exit();");

    Object logo = Object("", 165, 30, true);
    logo.setScale(1.1, 1.1);
    main_menu.addObject(logo);

    Object button = Object("", 250, 300, true);
    button.setScale(0.80, 0.80);
    button.onClick = "start();";
    button.onMouseMove = "change();";
    button.onMouseExit = "return();";
    std::cout << &test << std::endl;
    std::cout << &cache.getTexture("btn_start") << std::endl;
    //cache.createTexture("btn_start", "gfx\\GUI\\start.jpg", button.getSprite());
    button.setTexture(test/*cache.getTexture("btn_start")*/);
    main_menu.addObject(button);

    button = Object("", 250 , 400, true);
    button.setScale(0.80, 0.80);
    button.onClick = "next();";
    button.onMouseMove = "";
    button.onMouseExit = "";
    //button.setTexture(/*test*/*cache.getTexture("btn_options"));
    main_menu.addObject(button);

    button = Object("", 250, 500, true);
    button.setScale(0.80, 0.80);
    button.onClick = "exit();";
    button.onMouseMove = "";
    button.onMouseExit = "";
    //button.setTexture(cache.getTexture("btn_exit"));
    main_menu.addObject(button);

    /* Options */

    Frame options = Frame("gfx\\backgrounds\\background.png");
    options.setName("options");
    options.setKeyEvent(sf::Keyboard::Escape, "prev();");

    options.addObject(logo);

    button = Object("", 250, 300, true);
    button.setScale(0.80, 0.80);
    button.onClick = "";
    button.onMouseMove = "";
    button.onMouseExit = "";
    options.addObject(button);

    button = Object("", 250, 500, true);
    button.setScale(0.80, 0.80);
    button.onClick = "prev();";
    button.onMouseMove = "";
    button.onMouseExit = "";
    options.addObject(button);

    /* Room #1 */
    Frame room1 = Frame();
    room1.setName("game");
    room1.LoadData("maps\\map1.txt");
    room1.setKeyEvent(sf::Keyboard::Escape, "begin();");
    button = Object("player", 100, 100, true);
    //room1.addObject(button);
    room1.cacheObject(button);
    room1.addScript("move();");


    game.addFrame(main_menu);
    game.addFrame(options);
    game.addFrame(room1);
    game.Start();

    return 0;
}
