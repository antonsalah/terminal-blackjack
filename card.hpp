#pragma once
#include <iostream>
#include <string>
#include <ncursesw/ncurses.h>

enum Suit{
    heart,
    diamond,   
    club,
    spade
};

enum Value{
    ace, 
    two, 
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
    ten,
    jack,
    queen,
    king,
    usedAce
};
class Card {
    private:
        Value value;
        Suit suit;
    public:

        Card(Suit s, Value val){
            if ((s >= heart && s <= spade) && (val >= ace && val <= usedAce)){
                suit = s;
                value = val;
            }else{
                std::wcout << "OBJECT PARAMETERS NOT VALID!!!!\n";
            }
        }

        Card()= default;
       
        int getValue(){

            int result;
            if(value > ace && value < jack){
                result = value+1;
            }else if(value >= jack){
                result = 10;
            }else if(value == ace){
                result = 11;
            }else{
                result = 1;
            }
            return result; 
        }

        char getValueSymbol(){
            const char enumArr[] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K','A'};
                return enumArr[value];
        }
        Suit getSuit(){
            return suit;
        }

        const wchar_t getSuitSymbol(){

            switch(suit){
                case heart:
                    return 0x2665;
                    break;
                
                case diamond:
                    return 0x2666;
                    break;

                case club:
                    return 0x2663;
                    break;

                case spade:
                    return 0x2660;
                    break;

                default:
                    std::wcout << "ERROR CANT FIND SYMBOL!!!\n";
                    return 0x2550;
                
            }
        }

        void printCard(int x, int y) {
            mvprintw(x,y, ".-----.\n");
            x++;
            mvprintw(x,y, "| %c   |\n", getValueSymbol());
            x++;
            mvprintw(x,y, "|  %lc  |\n", getSuitSymbol());
            x++;
            mvprintw(x,y, "|   %c |\n", getValueSymbol());
            x++;
            mvprintw(x,y, "'-----'\n");
            refresh();
        }
};