#include "player.hpp"
#include "card.hpp" 
#include <cctype>
#include <ncursesw/ncurses.h>
#include <windows.h>

#define CENTER_X 15
#define CENTER_Y 50
#define PLAYER_BOTTOM 30
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
            clear();
        }

        int startRound(){
            user.drawCard();
            user.drawCard();
            if(user.checkBlackjack() == 0){
                printTable();
                mvprintw(CENTER_X,CENTER_Y,"Congrats! you got blackjack!");
                refresh();
                Sleep(1000);
                return 0;
            }
           
            dealer.drawCard();
            return -1;
        }

        playerOptions getPlayerChoice(){

            mvprintw(PLAYER_BOTTOM , CENTER_Y,"Press H(it), S(tay), D(ouble Down), Q(uit)");
            refresh();
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
            dealer.printHand(1);
            while(dealer.getScore() < 17){
                dealer.drawCard();
                if(dealer.getScore() > 21){
                    dealer.replaceAce();
                }
            }

            
            printTable();
        }

        int determineWinner(){
            //-1 dealer won, 0 tie, 1 user won
            unsigned userScore = user.getScore();
            unsigned dealerScore = dealer.getScore();

            move(CENTER_X,0);
            clrtoeol();

            if(userScore > 21){
                mvprintw(CENTER_X,CENTER_Y, "You Busted, Dealer wins"); 
                refresh();
                return -1;
            }else if(dealerScore > 21){
                mvprintw(CENTER_X,CENTER_Y, "Dealer Busted, You Win");
                refresh();
                return 1;
            }else if(dealerScore == userScore){
                mvprintw(CENTER_X,CENTER_Y, "Stand, no winner");
                refresh();
                return 0;
            }else if( dealerScore > userScore){
                mvprintw(CENTER_X,CENTER_Y, "Dealer's score is higher, Dealer wins");
                refresh();
                return -1;
            }else{
                mvprintw(CENTER_X,CENTER_Y,"Your score is higher, You Win!");
                refresh();
                return 1;
            }
        }

        int play(){

            //-1 == quit, 1 == bust
            bool done = false;
            while(!done){
                printTable();
                switch(getPlayerChoice()){

                    case Hit:
                        user.drawCard();
                        if(user.getScore() > 21){
                            if(user.replaceAce() == -1){
                                mvprintw(CENTER_X,CENTER_Y,"Your total is %d. You Busted ",user.getScore());
                                printTable();
                                done = true;
                                return 1;
                                //break;
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
                            mvprintw(CENTER_X,CENTER_Y, "Sorry, you can only Double Down on your first card");
                            refresh();
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
            mvprintw(0,30,"The Dealer's Hand");
            dealer.printHand(1);
            mvprintw(10,30,"The Dealer's Score is %d",dealer.getScore());
            mvprintw(17,30,"Your Hand");
            user.printHand(0);
            mvprintw(27,30,"Your Score is %d", user.getScore());
            refresh();

        }

        void runGame(){
            bool done = false;
            int playVal;
            while(!done){
                if(startRound() == -1){
                    playVal = play();
                    if(playVal == -1){
                        break;
                    }
                    if(playVal == 1){
                        getch();
                        resetRound();
                        continue;
                    }
                    playDealer();
                    determineWinner(); 
                }
                getch();
                resetRound();
            }
        }

};