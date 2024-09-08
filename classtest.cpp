#include <windows.h>
#include "player.hpp"
#include <iostream>
#include <string>
#include "card.hpp"
#include <io.h>
#include <fcntl.h>
#include <assert.h>
#include "game.hpp"
#include <ncursesw/ncurses.h>
#include <locale.h>
#include <wchar.h>
int test(){

    setlocale(LC_ALL, "en_US.UFT-8"); 
    initscr();

    Card test(Suit::heart,Value::ace);
    Suit testSuit = test.getSuit();
    assert(testSuit == heart);
    std::wcout << "Test 1 passed!" << std::endl;

    char testValue = test.getValueSymbol();
    assert(testValue == 'A');
    std::wcout << "Test 2 passed!" << std::endl;


    test.printCard(10,10);
    Sleep(1000);
    Card test2(Suit::diamond, Value::king);
    test2.printCard(10,20);
    Sleep(1000);
    

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

    clear();
    testPlayer.printHand(0);

    testPlayer.printHand(1);
    getch();

    std::wcout << "All of Test 5 Passed!" << std::endl;

    testPlayer.clearHand();
    testPlayer.printHand(0);
    std::wcout << "Test 6.1 Passed!" << std::endl;
    assert(testPlayer.getScore() == 0);
    std::wcout << "All of Tests 6 Passed!" << std::endl;

    testPlayer.clearHand();
    getch();

    Game game;
    game.runGame();

    endwin();
    testPlayer.drawThisCard(heart,ace);
    testPlayer.drawThisCard(heart,queen);

    assert(testPlayer.checkBlackjack() == 0);

    std::wcout << "Test 7 Passed!" << std::endl;

    return 0;
}
