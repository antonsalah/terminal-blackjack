#include <iostream>
#include <string>
#include "card.hpp"
#include <io.h>
#include <fcntl.h>
#include <assert.h>
int main(){
    Card test(spade,ace);
    _setmode(_fileno(stdout), _O_U16TEXT);

    Suit testSuit = test.getSuit();
    assert(testSuit == spade);
    std::wcout << "Test 1 pased!\n";

    char testValue = test.getValue();
    assert(testValue == 'A');
    std::wcout << "Test 2 passed!\n";


    test.printCard();
    std::wcout << "Test 3 Passed! \n";

    Card test2(diamond,ten);
    test2.printCard();
    
    Card test3(heart,queen);
    test3.printCard();

    return 0;
}
