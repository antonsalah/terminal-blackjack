#include "player.hpp"
#include "card.hpp" 
#include <cctype>

enum playerOptions{
    Hit,
    Stay,
    DoubleDown,
    Split,
    NA, //No Action
    Quit
};

class Game{
    private:

        Player user;
        Player dealer;

    public:

        Game(){}

        void resetRound(){
            user.clearHand();
            dealer.clearHand();
        }

        int startRound(){
            user.drawCard();
            user.drawCard();
            if(user.checkBlackjack() == 0){
                printTable();
                std::wcout << "Congraulations! You got Blackjack!" << std::endl;
                return 0;
            }
            dealer.drawCard();
            return -1;
        }

        playerOptions getPlayerChoice(){

            std::wcout << "Press H(it), S(tay), D(ouble Down), Q(uit)" << std::endl;
            char input;
            std::cin >> input;
            input = toupper(input);
            switch(input){
                case 'H':
                    return Hit;
                    break;

                case 'S':
                    return Stay;
                    break;

                case 'Q':
                    return Quit;
                    break;

                case 'D':
                    return DoubleDown;
                    break;

                default:
                    std::wcout << "Unknown input, please choose again" << std::endl;
                    return NA;
            }
        }

        void playDealer(){ 
            dealer.drawCard();
            while(dealer.getScore() < 17){
                dealer.drawCard();
                if(dealer.getScore() > 21){
                    dealer.replaceAce();
                }
            }
            
            std::wcout << "The dealer is done" << std::endl;
            printTable();
        }

        int determineWinner(){
            //-1 dealer won, 0 tie, 1 user won
            unsigned userScore = user.getScore();
            unsigned dealerScore = dealer.getScore();

            if(userScore > 21){
                std::wcout << "You Busted, Dealer wins" << std::endl;
                return -1;
            }else if(dealerScore > 21){
                std::wcout << "Dealer Busted, You Win" << std::endl;
                return 1;
            }else if(dealerScore == userScore){
                std::wcout << "Stand, no winners" << std::endl;
                return 0;
            }else if( dealerScore > userScore){
                std::wcout << "Dealer's score is higher, Dealer Wins" << std::endl;
                return -1;
            }else{
                std::wcout << "Your score is higher, You win!" << std::endl;
                return 1;
            }
        }

        int play(){
            bool done = false;
            while(!done){
                printTable();
                switch(getPlayerChoice()){

                    case Hit:
                        user.drawCard();
                        if(user.getScore() > 21){
                            if(user.replaceAce() == -1){
                                std::wcout << "Your total is " << user.getScore() << ". You Busted" << std::endl;
                                printTable();
                                done = true;
                            }
                        }
                        break;

                    case Stay:
                        done = true;
                        break;

                    case Quit:
                        return -1;

                    case DoubleDown:
                        if(user.getHandSize() > 2){
                            std::wcout << "Sorry, you can only Double Down your first Card" << std::endl;
                        }else{
                            user.drawCard();
                            done = true;
                        }
                        if(user.getScore() > 21){
                            user.replaceAce();
                        }
                        
                        break;

                    default:
                        break;
                }
            }
            return 0;
        }

        void printTable(){
            std::wcout << "The Dealer's Hand" << std::endl;
            dealer.printHand(1);
            std::wcout << "The Dealer's Score is " << dealer.getScore() << std::endl;
            std::wcout << "Your Hand" << std::endl;
            user.printHand(0);
            std::wcout << "Your Score is " << user.getScore() << std::endl;

        }

        void runGame(){
            bool done = false;
            while(!done){
                if(startRound() == -1){
                    if(play() == -1){
                        break;
                    }
                    playDealer();
                    determineWinner(); 
                }
                resetRound();
            }
        }

};