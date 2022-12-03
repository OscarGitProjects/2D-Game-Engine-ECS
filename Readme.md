This is a C++ project i have done to learn to do a 2D game engine with the ECS (Entity, Component, System) architectural pattern.
It's more of a code demo than a demo of nice graphics. But the basic functions are here. In this project i dont use a config file.
I use the SFML graphics library for the rendering to the computer screen. https://www.sfml-dev.org

It is a simple game where the player has to shoot down incoming shapes. 
There are some random things here. As the color, speed, direction that the shapes are moving, Number of vertices that the shape has and Health.

You control your shape with the keys W, S, A and D. Pause the game with P. Unpause the game by pressing P again. Press space bar and you die.
Press Esc to end the game. You shoot bullets with the left mouse button. With the right mouse button you can use the special weapon. 
You get the special weapon when you have got x number of points.

I learned this with the help of training videos on youtube and reading about it on the internet.
You can read more aboute the ECS architectural pattern at the following links
https://en.wikipedia.org/wiki/Entity_component_system
https://www.simplilearn.com/entity-component-system-introductory-guide-article
https://www.guru99.com/entity-component-system.html


I have developed this in Microsoft Visual Studio 2022 Community edition. 
First you download SFML graphics library from https://www.sfml-dev.org/download/sfml/2.5.1/

Unpack it to a directory on your computer. No spaces in the path. 
Example from my computer C:\libraries\SFML-2.5.1-windows-vc15-64-bit\SFML-2.5.1

The you have to set a Environment Variable with the path to the directory with SFML. 
I call it SFML_DIR and the path is C:\libraries\SFML-2.5.1-windows-vc15-64-bit\SFML-2.5.1. 
Then you add a path variable pointing to the bin directory with the dll files. SFML_DIR. On my computer i do this %SFML_DIR%\bin

In your Microsoft Visual Studio environment you have to do some settings to. 
Follow the tutorial at SFML homepage. https://www.sfml-dev.org/tutorials/2.5/start-vc.php

