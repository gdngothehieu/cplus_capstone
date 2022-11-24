# CPPND Capstone: Blackjack Simulation

This is the Capstone project for the Udacity C++ Nanodegree course. A Blackjack game is simulated using varius C++ topics, including OOP and Smart Pointers. After running the program, the user gets prompted through a single Deck game of Blackjack in the Terminal. This game does not include any special Blackjack Rules.

## Game Logic
The created Simulation is a basic and simplified Blackjack game. The goal is to beat the dealer with getting as close to 21 as possible without ending above this number. 
In this Simulation, no *double downs* or *splits* are possible, it's either *hit* or *stand*. The Dealer stands on Soft 17 and Aces count as 11 or 1. This game is a single Deck game and up to 4 players in total can play in each game. The "Cut Card" is at about 30 cards left, at what point the deck will be shuffled again. No money or chips are involved.

## Project Structure
This project is devided into two main .cpp files and their included .h files. The "deck.cpp" file covers the initialization of the deck, including the cards and their ranks/suits. Also a part are functions that handle the shuffle and the printing of the cards/deck as well as checking the score of the players hand. The "game.cpp" file includes the game loop and the regarding game logic. 
The player interacts with the program over the Terminal/Console. The player will be walked through the game and gets any information he needs to play the game and beat the Dealer.

## Rubric Points addressed

The following points covered in the C++ Nanodegree course are included in this program:
* Loops, Functions, I/O
  * The project demonstrates an understanding of C++ functions and control structures | See deck.cpp and game.cpp
  * The project accepts user input and processes the input | See game.cpp in various code lines
* Object Oriented Programming
  * The project uses Object Oriented Programming Techniques | See deck.cpp and game.cpp
  * Classes use appropriate access specifiers for class members | See deck.h and game.h (i.e class *Card*)
  * Classes abstract implementation details from their interfaces | See deck.cpp and game.cpp
  * Classes encapsulate Behavior | See class *Card* in deck.h)
* Memory Management
  * The project makes use of references in function declarations | see functions in deck.h and game.h
  * The class uses smart pointers instead of raw pointers | see class "Game" in game.h
  
## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./Capstone`.
