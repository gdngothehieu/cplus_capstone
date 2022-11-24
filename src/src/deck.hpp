//
//  deck.hpp
//  src
//
//  Created by David Schulte Südhoff on 11/5/20.
//  Copyright © 2020 David Schulte Südhoff. All rights reserved.
//

#ifndef deck_hpp
#define deck_hpp
#include <vector>
#include <iostream>

// Define all possible Rank and Suit of cards
enum Rank
{
    Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace
};

enum Suit
{
    Spades, Heards, Clubs, Diamonds
};


// Define the class Card
class Card {
    
public:
    int value;
    int num_rank = 13;
    int num_suit = 4;
    
    // Getters and Setters for Card features (Suit and Rank)
    void setRank(int rank)
    {
        rank_ = Rank(rank);
    }
    Rank getRank() const {return rank_; }
    
    void setSuit(int suit)
    {
        suit_ = Suit(suit);
    }
    Suit getSuit() const {return suit_; }
    
private:
    Rank rank_;
    Suit suit_;
};

// Define the Deck containing of the Cards
class Deck{
public:
    std::vector<Card> cards;
    
    void initialize_deck(Deck&);
    void print_deck(const Deck&);
    void shuffle(Deck&);
};

void print_hand(const std::vector<Card>&);
void print_card(Card&);
void print_rank(Rank&);
void print_suit(Suit&);
int get_value(Rank);
int check_score(const std::vector<Card>&);

#endif /* deck_hpp */
