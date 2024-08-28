#include "player.hpp"
#include "card.hpp" 

enum playerOptions{
    hit,
    stay,
    DoubleDown,
    Split
};

class Game{
    private:

        Player user;
        unsigned userScore;
        Player dealer;
        unsigned dealerScore;

    public:

        unsigned getScore(){
            //todo
        }

        void addScore(Card newCard){
            //todo
        }

        void resetRound(){
           //todo: reset both players hands and scores
        }

        void startRound(){
            //todo: deal starting cards to user and first card to dealer
        }

        playerOptions getPlayerChoice(){
            //todo
            //get player input
            //check to see if valid choice
            //return option
        }

        void playDealer(){
            //todo
            //Once player makes their choice, play out the dealer according to rules, then decide who wins
        }

        bool checkIfOverCount(){
            //todo see if the score for the player object is over 21
        }

};