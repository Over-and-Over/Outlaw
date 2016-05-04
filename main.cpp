#include <iostream>
#include <SFML/Graphics.hpp>
#include "engine.h"
#include "frame.h"
#include "object.h"
#include "cache.h"

int main()
{
    Engine game = Engine(2, "Outlaw");

    sf::Texture txt;
    txt.loadFromFile("gfx\\GUI\\start.jpg");
    std::cout << "in main: " << &txt << std::endl;

    /* Main menu */
    Frame main_menu = Frame("gfx\\backgrounds\\background.png");
    main_menu.setName("menu");
    main_menu.setKeyEvent(sf::Keyboard::Escape, "exit();");

    Object logo("logo", 165, 30, &txt);
    logo.setScale(1.1, 1.1);
    main_menu.addObject(&logo);

    Object button("start", 250, 300, &txt);
    button.setScale(0.80, 0.80);
    button.onClick = "start();";
    button.onMouseMove = "change();";
    button.onMouseExit = "return();";
    main_menu.addObject(&button);

    Object button2("options", 250 , 400, &txt);
    button2.setScale(0.80, 0.80);
    button2.onClick = "next();";
    button2.onMouseMove = "";
    button2.onMouseExit = "";
    main_menu.addObject(&button2);

    Object button3("exit", 250, 500, &txt);
    button3.setScale(0.80, 0.80);
    button3.onClick = "exit();";
    button3.onMouseMove = "";
    button3.onMouseExit = "";
    main_menu.addObject(&button3);

    /* Options */
    /*Frame options = Frame("gfx\\backgrounds\\background.png");
    options.setName("options");
    options.setKeyEvent(sf::Keyboard::Escape, "prev();");

    options.addObject(logo);

    button = Object("", 250, 300, test2);
    button.setScale(0.80, 0.80);
    button.onClick = "";
    button.onMouseMove = "";
    button.onMouseExit = "";
    options.addObject(button);

    button = Object("", 250, 500, test2);
    button.setScale(0.80, 0.80);
    button.onClick = "prev();";
    button.onMouseMove = "";
    button.onMouseExit = "";
    options.addObject(button);*/

    /* Room #1 */
    /*Frame room1 = Frame();
    room1.setName("game");
    room1.LoadData("maps\\map1.txt");
    room1.setKeyEvent(sf::Keyboard::Escape, "begin();");
    button = Object("player", 100, 100);
    //room1.addObject(button);
    room1.cacheObject(button);
    room1.addScript("move();");*/

    game.addFrame(&main_menu);
    //game.addFrame(options);
    //game.addFrame(room1);
    game.Start();

    return 0;
}
