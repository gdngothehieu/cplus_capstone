//
//  deck.cpp
//  src
//
//  Created by David Schulte Südhoff on 11/5/20.
//  Copyright © 2020 David Schulte Südhoff. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include "deck.hpp"
#include "game.hpp"


void print_rank(Rank r) {
// get name of enum class
   switch(r) {
      case Two:
         std::cout << "2";
         break;
      case Three:
         std::cout << "3";
         break;
      case Four:
         std::cout << "4";
         break;
      case Five:
         std::cout << "5";
         break;
      case Six:
         std::cout << "6";
         break;
      case Seven:
         std::cout << "7";
         break;
      case Eight:
         std::cout << "8";
         break;
      case Nine:
         std::cout << "9";
         break;
      case Ten:
         std::cout << "10";
         break;
      case Jack:
         std::cout << "Jack";
         break;
      case Queen:
         std::cout << "Queen";
         break;
      case King:
         std::cout << "King";
         break;
      case Ace:
         std::cout << "Ace";
         break;
   }
}


void print_suit(Suit s) {
// get name of suit of enum class
switch(s) {
   case Spades:
      std::cout << "♠️";
      break;
   case Heards:
      std::cout << "♥️";
      break;
   case Clubs:
      std::cout << "♣️";
      break;
   case Diamonds:
      std::cout << "♦️";
      break;
   }
}


int get_value(Rank r) {
// get value of card of enum class
   int value;
   switch(r) {
      case Two:
         value = 2;
         break;
      case Three:
         value = 3;
         break;
      case Four:
         value = 4;
         break;
      case Five:
         value = 5;
         break;
      case Six:
         value = 6;
         break;
      case Seven:
         value = 7;
         break;
      case Eight:
         value = 8;
         break;
      case Nine:
         value = 9;
         break;
      case Ten:
         value = 10;
         break;
      case Jack:
         value = 10;
         break;
      case Queen:
         value = 10;
         break;
      case King:
         value = 10;
         break;
      case Ace:
         value = 11;
         break;
   }
   return value;
}


void Deck::initialize_deck(Deck& deck)
// Filling the Deck with the appropriate specific cards
{
    std::cout << "This is a single Deck Game" << std::endl;
    Card card;
    for (int suit = 0; suit < card.num_suit; suit++)
    {
        for (int rank = 0; rank < card.num_rank; rank++)
        {
            card.setSuit(suit);
            card.setRank(rank);
            deck.cards.push_back(card);
        }
    }
}


void Deck::print_deck(const Deck& deck)
{
    for (Card c : deck.cards)
    {
        print_card(c);
    }
}


void print_hand(const std::vector<Card>& hand)
{
    for (Card c : hand)
    {
        print_card(c);
    }
}


void print_card(Card& card)
{
    print_suit(card.getSuit());
    std::cout << " "; // Space between suit and number 
    print_rank(card.getRank());
    std::cout << '\n';
}


void Deck::shuffle(Deck& deck)
{
    std::cout << "Deck will be shuffled" << std::endl;
    std::this_thread::sleep_for (std::chrono::seconds(2));
    Deck shuffled;
    // Pull random cards from the deck and push it into shuffled.cards vector
    // Delete pulled card after pushing it into shuffled object
    srand( static_cast<unsigned int>(time(nullptr))); //ensures random cards after each shuffle
    while (!deck.cards.empty())
    {
        size_t rand_card = rand() % deck.cards.size();
        shuffled.cards.push_back(deck.cards[rand_card]);
        deck.cards.erase(deck.cards.begin() + rand_card);
    }
    deck = shuffled;
}

int check_score(const std::vector<Card>& hand)
{
    // Loop over card values of hand and return the score
    int score = 0;
    // declaring two Aces in case players gets two aces in one hand
    bool ace1 = false;
    bool ace2 = false;
    for (int card=0; card<hand.size(); card++)
    {
        score = score + get_value(hand[card].getRank());
        
        // Aces get handled uniquely since their value is either 1 or 11
        if (get_value(hand[card].getRank()) == 11)
        {
            if (ace1 == true)
            {
                ace2 = true; //setting ace2 to true if second ace appears in hand
            }
            else
            {
                ace1 = true; //setting ace1 to true when first ace appears in hand
            }
        }
        if (score > 21 && ace1 == true)
        {
            if (ace2 == true)
            {
                score = score-10;
                ace2 = false; // ace2 is set to value 1 when player surpasses 21
            }
            else
            {
                score = score-10;
                ace1 = false; // ace1 is set to value 1 if player surpasses 21 again
            }
        }
    }
    return score;
}
