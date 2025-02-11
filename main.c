#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
typedef struct Player
{
    int xPosition;
    int yPosition;
    int health;

}Player;

Player * player_SetUp();

int screenSetUp();
int mapSetUp();
int handleInput(int input, Player * user);
int playerMove(int y, int x, Player * user);



int main()
{
    Player * user;
    int ch;
    screenSetUp();

    mapSetUp();
    user = player_SetUp();

    /* main game loop */
    while((ch = getch()) != 'q')
    {
        handleInput(ch, user);

    }


    endwin();

    return 1;
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

    playerMove(14, 14, newPlayer);
    return newPlayer;

}

int handleInput(int input, Player  * user)
{
    switch(input)
    {
        /*move up*/
        case 'w':
        case 'W':
            playerMove(user->yPosition-1, user->xPosition, user);
            break;
        /*move down*/
        case 's':
        case 'S':
            playerMove(user->yPosition+1, user->xPosition, user);
            break;
        /*move left*/
        case 'a':
        case 'A':
            playerMove(user->yPosition, user->xPosition-1, user);
            break;
        /*move right*/
        case 'd':
        case 'D':
            playerMove(user->yPosition, user->xPosition+1, user);
            break;

        default:
            break;
    }
}

int playerMove(int y, int x, Player * user)
{

    mvprintw(user->yPosition, user->xPosition, ".");
    //move(newPlayer->yPosition,newPlayer->xPosition);
    user->yPosition = y;
    user->xPosition = x;
    mvprintw(user->yPosition, user->xPosition, ".");
    move(user->yPosition, user->xPosition);

}

