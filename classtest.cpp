#include <iostream>
#include "card.hpp"
#include <assert.h>
int main(){
    Card test(spade,ace);

    Suit testSuit = test.getSuit();
    assert(testSuit == spade);
    std::cout << "Test 1 passed!\n";
    Value testValue = test.getValue();
    assert(testValue == 'A');
    std::cout << "Test 2 passed!\n";
    test.printCard();
    return 0;
}
