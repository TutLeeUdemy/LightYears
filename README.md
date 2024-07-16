# Light Years

### Introduction to the Game

Light Years is a 2D scrolling shooter spaceship fighting game, the player controls the hero spaceship and defeat the alien invation.
The Game is written in ```C++``` and the following library:
* [SFML](https://www.sfml-dev.org/) 
* [Box2D](https://box2d.org/)

### Screen Captures
<image src="doc/assets/capture01.png" width=200>
<image src="doc/assets/capture02.png" width=200>
<image src="doc/assets/capture03.png" width=200>
<image src="doc/assets/capture04.png" width=200>

### How to Build
The project uses ```cmake``` to configure the project and dependencies. Make sure your system have ```cmake``` and ```gcc/g++``` installed:
|Tool Chain|Version|
|---------------------|------|
|cmake version:       |3.27.7|
|C++ version:         |C++ 14|
|Generator:           |Ninja | 

The build process is very generic:

1, Open the folder with command prompt, and configure with cmake:
```
cmake -S . -B build -G Ninja
```
2, Build with cmake:
```
cmake --build build
```
3, open the game:
```
./build/LightYearsGame/LightYearsGame.exe
```
You can also run ```buildAndRun.bat``` to do all the above steps in one go.

### Technical Details

The game is broken down to 2 major projects:

* LightYearsEngine
* LightYearsGame
________________
The ```LightYearsEngine``` is a minimal game engine build on top of SFML that has the following implementations:
* Appliation

    the ```Application``` class is the top level object of the game that handles:
    -  window creation
    -  game loop
    -  rendering
    -  level loading
    -  event dispatching
    -  Input

* World
    the ```World``` class represent a game level, it handles:
    - Actor Spawning
    - HUD Spawning
    - Object Lifetime Management
    - Game Stage Management

* Actor

    The ```Actor``` represent a game object than can be place in the level, they have facilities to change their ```location```, ```rotation```, and ```visuals```.

* Asset Manager

    The ```AssetManager``` class is the core object to manage ```Fonts``` and ```Textures```, allowing easy loading, and memeory management of the resources.

* Physics System

    The ```PhysicsSystem``` uses [Box2D](https://box2d.org/) as the Physics Engine, enabling Actors to trigger overlapping events.

* Timer Manager

    The ```TimerManager``` provide easy timer creation, manages life time, looping, and callbacks. 

* Delegates

    The ```Delegate``` class allows easy object member function binding and callbacks which helps creating event driven code.

* Widgets

    The ```Widget``` classes are used for UI elements, and currently have:
    * Button
    * Image
    * Text
    * Value Gauge (progress bar)
        
____________
The ```LightYearsGame``` is the actual game build on top of ```LightYearsEngine```, and it has the following major components:

*  
