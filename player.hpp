#include <ctime>
#include <cstdlib>
#include "card.hpp"

class Player{
    private:
    Card hand[20];

    public:

    void addCard(Card newCard){

    }

    void drawCard(){
        //do check handeling. IE see if the hand if full and do stuff if so.
        std::srand((unsigned)std::time(NULL));
        int randNumGen = rand() % 52; 

        Suit s = static_cast<Suit>(randNumGen % 4);
        Value val = static_cast<Value>(randNumGen % 13);

        Card newCard(s,val);
        //addCard(newCard);
    }

    void clearHand(){
        //todo
    }
};