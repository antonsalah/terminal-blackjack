#include "player.hpp"
#include "card.hpp" 

enum playerOptions{
    Hit,
    Stay,
    DoubleDown,
    Split,
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

        void startRound(){
            //todo: deal starting cards to user and first card to dealer
            user.drawCard();
            user.drawCard();
            dealer.drawCard();

            std::wcout << "Dealer's Hand" << std::endl;

            dealer.printHand();

            std::wcout << "Your Hand" << std::endl; 
            user.printHand();
        }

        playerOptions getPlayerChoice(){
            //todo
            //get player input
            //check to see if valid choice
            //return option

            std::wcout << "Press H(it), S(tay), Q(uit)" << std::endl;
            char input;
            std::cin >> input;
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

                default:
                    std::wcout << "Unknown input!!! you have choicen to Stay" << std::endl;
                    return Stay;
            }
        }

        void playDealer(){//need to return who wins//
            //todo
            //Once player makes their choice, play out the dealer according to rules, then decide who wins
            dealer.drawCard();
            unsigned runningScore = dealer.getScore();
            while(runningScore < 17){
                dealer.drawCard();
            }
            std::wcout << "The dealer is done. The dealer's score is " << runningScore;

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

        void play(){
            bool done = false;
            while(!done){
                user.printHand();
                switch(getPlayerChoice()){

                    case Hit:
                        user.drawCard();
                        if(user.getScore() > 21){
                            std::wcout << "Your total is " << user.getScore() << ". You busted" << std::endl;
                            done = true;
                        }

                        break;

                    case Stay:
                        done = true;

                        break;

                    case Quit:
                        resetRound();// this needs to be changed to actually quit the program
                        break;

                    default:
                        std::wcout <<"Unknown Command" << std::endl;
                }
            }
            playDealer();
        }

};