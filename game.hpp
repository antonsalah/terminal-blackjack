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
            user.drawCard();
            user.drawCard();
            dealer.drawCard();

            std::wcout << "Dealer's Hand" << std::endl;

            dealer.printHand();

            //std::wcout << "Your Hand" << std::endl; 
        }

        playerOptions getPlayerChoice(){

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

        void playDealer(){
            dealer.drawCard();
            unsigned runningScore = dealer.getScore();
            while(runningScore < 17){
                dealer.drawCard();
                runningScore = dealer.getScore();
            }
            std::wcout << "The dealer is done. The dealer's score is " << runningScore << std::endl;

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
                std::wcout << "Your Hand" << std::endl;
                user.printHand();
                std::wcout << "Your current score " << user.getScore() << std::endl;
                switch(getPlayerChoice()){

                    case Hit:
                        user.drawCard();
                        if(user.getScore() > 21){
                            if(user.replaceAce() == -1){
                                std::wcout << "Your total is" << user.getScore() << ". You Busted" << std::endl;
                                done = true;
                            }
                        }
                        break;

                    case Stay:
                        done = true;
                        break;

                    case Quit:
                        return -1;

                    default:
                        std::wcout <<"Unknown Command" << std::endl; //might change this to be blank to allow retyping of choice
                }
            }
            return 0;
        }

        void runGame(){
            bool done = false;
            while(!done){
                startRound();
                if(play() == -1){
                    break;
                }
                playDealer();
                determineWinner(); 
                resetRound();
            }
        }

};