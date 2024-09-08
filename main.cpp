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

int main(){
    //test();
    setlocale(LC_ALL, "en_US.UFT-8"); 
    initscr();

    Game game;
    game.runGame();

    
    return 0;
}