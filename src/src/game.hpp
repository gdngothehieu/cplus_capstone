//
//  game.hpp
//  src
//
//  Created by David Schulte Südhoff on 11/6/20.
//  Copyright © 2020 David Schulte Südhoff. All rights reserved.
//

#ifndef game_hpp
#define game_hpp

#include <stdio.h>
#include <vector>
#include <memory>
#include "deck.hpp"

struct Player {
    std::vector<Card> hand;
    int score;
};

class Game {
public:
    
   // Game() : players(std::vector<std::make_unique<Player>>()) {}
    
    std::vector<std::shared_ptr<Player>> players;
    
    Player dealer;
    int num_players;
    Deck deck;
    // Getter function to access number of dealt cards in first round
    int get_cards_per_hand() const {return cards_per_hand_; }
    
    void initialize(Game&);
    void game_loop(Game&);
    void add_players(Game&);
    void play_round(Game&);
    void dealer_move(Game&);
    void compare_score(Game&);
    
private:
    int cards_per_hand_ = 2;
};

void deal_cards(Game&);
void print_game(const Game&);
char make_decision();
bool check_blackjack(int);
bool all_player_bust(Game&);
void clear_hands(Game&);

#endif /* game_hpp */
    
