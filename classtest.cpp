#include <windows.h>
#include "player.hpp"
#include <iostream>
#include <string>
#include "card.hpp"
#include <io.h>
#include <fcntl.h>
#include <assert.h>
int main(){
    Card test(Suit::spade,Value::ace);
    _setmode(_fileno(stdout), _O_U16TEXT);

    Suit testSuit = test.getSuit();
    assert(testSuit == spade);
    std::wcout << "Test 1 pased!\n";

    char testValue = test.getValue();
    assert(testValue == 'A');
    std::wcout << "Test 2 passed!\n";


    test.printCard();
    std::wcout << "Test 3 Passed! \n";

    Card test2(Suit::diamond,Value::ten);
    test2.printCard();
    
    Card test3(Suit::heart,Value::queen);
    test3.printCard();

    std::wcout << "Test 4 Passed! \n";

    Player testPlayer;
    testPlayer.drawCard();
    testPlayer.drawCard();
    testPlayer.drawCard();
    testPlayer.printHand();

    std::wcout << "Test 5 Passed! \n";

    return 0;
}
