#include <ctime>
#include <cstdlib>
#include "card.hpp"
#include <windows.h>

const int handSize = 20;
class Player{
    private:
    Card hand[handSize];
    int currIndex;

    public:

        Player(){
            currIndex = 0;
        }


        void addCard(Card newCard){
            if(currIndex < handSize){
                hand[currIndex] = newCard;
                currIndex++;
            }else{
            //incase hand gets to big
            }

        }

        void drawCard(){
            Sleep(50); //Ensures that back-to-back drawings produces different cards.
            int randTime = GetTickCount();
            std::srand((unsigned)randTime);
            std::wcout << randTime << std::endl;
            int randNumGen = rand() % 52; 

            Suit s = static_cast<Suit>(randNumGen % 4);
            Value val = static_cast<Value>(randNumGen % 13);

            Card newCard(s,val);
            addCard(newCard);
        }

        void clearHand(){
            //todo
        }

        void printHand(){
            for(int i = 0; i < currIndex; i++){
                hand[i].printCard();
            }
        }
};