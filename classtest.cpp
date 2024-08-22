#include <iostream>
#include "card.hpp"
#include <assert.h>
int main(){
    Card test(spade,ace);

    Suit testSuit = test.getSuit();
    assert(testSuit == 3);
    std::cout << "Test 1 passed!\n";
    Value testRank = test.getValue();
    assert(testRank == 1);
    std::cout << "Test 2 passed!\n";
    return 0;
}
