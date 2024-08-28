#pragma once
#include <ctime>
#include <cstdlib>
#include "card.hpp"
#include <windows.h>
#include <vector>
class Player{
    private:
    std::vector<Card*> hand;
    public:

        Player(){}


        void addCard(Card* newCard){
            hand.push_back(newCard);
        }

        void drawCard(){
            Sleep(50); //Ensures that back-to-back drawings produces different cards.
            std::srand((unsigned)GetTickCount());
            int randNumGen = rand() % 52; 

            Suit s = static_cast<Suit>(randNumGen % 4);
            Value val = static_cast<Value>(randNumGen % 13);

            Card* newCard = new Card(s,val);
            addCard(newCard);
        }

        void clearHand(){
            while(!hand.empty()){
                delete hand.back();
                hand.pop_back();
            }
        }
        void printHand(){
            if(!hand.empty()){
                for(unsigned i = 0; i< hand.size(); i++){
                    hand[i] -> printCard();
                }
            }
        }
};