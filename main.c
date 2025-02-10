#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
typedef struct Player
{
    int xPosition;
    int yPosition;
    int health;

}Player;

int screenSetUp();
int mapSetUp();
Player * player_SetUp();

int main()
{
    Player * user;
    int ch;
    screenSetUp();

    mapSetUp();
    user = player_SetUp();

    while((ch = getch()) != 'q')
    {


    }


    endwin();

    return 0;
}
int screenSetUp()
{
    initscr();
    printw("Rogue");
    noecho();
    refresh();

    return 0;
}

int mapSetUp()
{
    mvprintw(13, 13, "--------");
    mvprintw(14, 13, "|******|");
    mvprintw(15, 13, "|******|");
    mvprintw(16, 13, "|******|");
    mvprintw(17, 13, "|******|");
    mvprintw(18, 13, "--------");

    mvprintw(2, 40, "--------");
    mvprintw(3, 40, "|******|");
    mvprintw(4, 40, "|******|");
    mvprintw(5, 40, "|******|");
    mvprintw(6, 40, "|******|");
    mvprintw(7, 40, "--------");


    mvprintw(10, 40, "------------");
    mvprintw(11, 40, "|**********|");
    mvprintw(12, 40, "|**********|");
    mvprintw(13, 40, "|**********|");
    mvprintw(14, 40, "|**********|");
    mvprintw(15, 40, "------------");
}

Player * player_SetUp()
{
    Player * newPlayer;
    newPlayer = malloc(sizeof(Player));
    newPlayer->xPosition = 14;
    newPlayer->yPosition = 14;
    newPlayer->health = 20;

    mvprintw(newPlayer->yPosition, newPlayer->xPosition, "@");
    move(newPlayer->yPosition,newPlayer->xPosition);
    return newPlayer;

}



