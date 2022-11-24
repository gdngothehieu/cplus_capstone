//
//  main.cpp
//
//  Created by David Schulte Südhoff on 11/4/20.
//  Copyright © 2020 David Schulte Südhoff. All rights reserved.
//  Udacity Capstone Project
//

#include <iostream>
#include <vector>
#include <thread>
#include "deck.hpp"
#include "game.hpp"

int main() {
    std::cout << '\n';
    std::cout << "♤♤♤♤♤♤♤♤♤♤♤♤♤♤ BLACKJACK ♤♤♤♤♤♤♤♤♤♤♤♤♤♤" << std::endl;
    
    Game game;
    game.initialize(game);
    game.game_loop(game);
    
    std::cout << '\n';
    std::cout << "♤♤♤♤♤♤♤♤♤♤♤♤♤♤♤♤♤♤♤♤♤♤♤♤♤♤♤♤♤♤♤♤♤♤♤♤♤♤♤" << std::endl;
}

