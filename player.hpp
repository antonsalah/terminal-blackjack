#pragma once
#include "card.hpp"
#include <windows.h>
#include <vector>
class Player{
    private:

        std::vector<Card*> hand;
        unsigned score = 0;

        void addCard(Card* newCard){
            add2Score(*newCard);
            hand.push_back(newCard);
        }

        void add2Score(Card newCard){
            int newAddition = newCard.getValue();
            score += newAddition;
        }

        void sub2Score(){//only happens in event of an ace(11) turning into a usedAce(1)
            score -= 10;
        }

    public:

        Player(){}

        void drawCard(){
            Sleep(50); //Ensures that back-to-back drawings produces different cards.
            std::srand((unsigned)GetTickCount());
            int randNumGen = rand() % 52; 

            Suit s = static_cast<Suit>(randNumGen % 4);
            Value val = static_cast<Value>(randNumGen % 13);

            Card* newCard = new Card(s,val);
            addCard(newCard);
        }

        Card* getLatestCard(){
            return hand.back();
        }

        unsigned getScore(){
            return score;
        }

        void clearHand(){
            while(!hand.empty()){
                delete hand.back();
                hand.pop_back();
            }
            score = 0;
        }

        int replaceAce(){

            bool found = false;
            unsigned index = 0;
            while(!found && index < hand.size()){
                if(hand[index]->getValue() == 11){
                    Card* newAce = new Card(hand[index]->getSuit(), usedAce);
                    delete hand[index];
                    hand[index] = newAce;
                    sub2Score();
                    found = true;
                }else{
                    index++;
               }
            }

            if(found == false){
                return -1;
            }else{
                return 0;
            }
        }

        void printHand(int side){
            int x;
            if(side == 0){
                x = 20;//player
            }else{
                x=0; //dealer
            }
            if(!hand.empty()){
                for(unsigned i = 0; i< hand.size(); i++){
                    hand[i] -> printCard(x,i*10);
                }
            }
        }

        int getHandSize(){
            return hand.size();
        }

        void drawThisCard(Suit s, Value val){ //used in debugging only//
            Card* newCard = new Card(s,val);
            addCard(newCard);
        }

        int checkBlackjack(){
            if(hand[0]->getValueSymbol() == 'A' || hand[1]->getValueSymbol() == 'A'){
                if(hand[0]->getValue() == 10 || hand[1]->getValue() == 10){
                    return 0;
                }
            }
            return -1;
        }
};