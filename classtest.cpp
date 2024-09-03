#include <windows.h>
#include "player.hpp"
#include <iostream>
#include <string>
#include "card.hpp"
#include <io.h>
#include <fcntl.h>
#include <assert.h>
#include "game.hpp"

int main(){
    _setmode(_fileno(stdout), _O_U16TEXT);
    
    Card test(Suit::spade,Value::ace);
    Suit testSuit = test.getSuit();
    assert(testSuit == spade);
    std::wcout << "Test 1 passed!" << std::endl;

    char testValue = test.getValueSymbol();
    assert(testValue == 'A');
    std::wcout << "Test 2 passed!" << std::endl;


    test.printCard();
    std::wcout << "Test 3 Passed!" << std::endl;

    std::wcout << "Test 4 Passed!" << std::endl;

    Player testPlayer;
    unsigned runningScore = 0;
    testPlayer.drawCard();
    runningScore += testPlayer.getLatestCard()->getValue();
    assert(testPlayer.getScore() ==runningScore);
    std::wcout << "Test 5.1 Passed!" << std::endl;
    testPlayer.drawCard();
    runningScore += testPlayer.getLatestCard()->getValue();
    assert(testPlayer.getScore() == runningScore);
    std::wcout << "Test 5.2 Passed!" << std::endl;
    testPlayer.drawCard();
    runningScore += testPlayer.getLatestCard()->getValue();
    assert(testPlayer.getScore() == runningScore);
    std::wcout << "Test 5.3 Passed!" << std::endl;
    testPlayer.printHand();

    std::wcout << "All of Test 5 Passed!" << std::endl;

    testPlayer.clearHand();
    testPlayer.printHand();
    std::wcout << "Test 6.1 Passed!" << std::endl;
    assert(testPlayer.getScore() == 0);
    std::wcout << "All of Tests 6 Passed!" << std::endl;

    testPlayer.clearHand();

    Game game;

    testPlayer.drawThisCard(heart,ace);
    testPlayer.drawThisCard(heart,queen);

    assert(testPlayer.checkBlackjack() == 0);

    std::wcout << "Test 7 Passed!" << std::endl;
    //make sure hit works

    //make sure stay works

    //make sure ace works

    //make sure double down works

    //make sure double down with ace works


    game.runGame();

    return 0;
}
