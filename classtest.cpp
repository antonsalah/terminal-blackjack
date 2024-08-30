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

    Card test2(Suit::diamond,Value::ten);
    std::wcout << "This should print a ten of diamonds" << std::endl;
    test2.printCard();
    
    Card test3(Suit::heart,Value::queen);
    std::wcout << "This should print a Queen of Hearts" << std::endl;
    test3.printCard();

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

    bool done = false;
    Game game;
    while(!done){
       game.startRound();
       game.play();
       game.determineWinner(); 
    }

    return 0;
}
