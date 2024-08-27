#pragma once
#include <iostream>
#include <string>
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
    king
};
class Card {
    private:
        Value value;
        Suit suit;
    public:

        Card(Suit s, Value val){
            if ((s >= heart && s <= spade) && (val >= ace && val <= king)){
                suit = s;
                value = val;
            }else{
                std::wcout << "OBJECT PARAMETERS NOT VALID!!!!\n";
            }
        }

        Card()= default;

        char getValue(){
            const char enumArr[] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
                return enumArr[value];
        }
        Suit getSuit(){
            return suit;
        }

        std::wstring getSuitSymbol(){

            switch(suit){
                case heart:
                    return L"♥";
                    break;

                case diamond:
                    return L"♦";
                    break;

                case club:
                    return L"♣";
                    break;

                case spade:
                    return L"♠";
                    break;

                default:
                    std::wcout << "ERROR CANT FIND SYMBOL!!!\n";
                    return L"?";
            }
        }

        void printCard(){
            std::wcout << ".-----."<< std::endl;
            std::wcout << "|" << getValue() << "    |" <<std::endl;
            std::wcout << "|  " << getSuitSymbol() << "  |" << std::endl;
            std::wcout << "|    " <<getValue()<<"|" << std::endl;
            std::wcout << "'-----'" << std::endl;
        }



};