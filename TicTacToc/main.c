// usr/bin/clang "$0" && exec ./a.out "$@"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

// Font code colours
#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define BLU "\x1B[34m"
#define MAG "\x1B[35m"
#define CYN "\x1B[36m"
#define WHT "\x1B[37m"
// back ground code colours
#define gRED "\x1B[41m"
#define gGRN "\x1B[42m"
#define gYEL "\x1B[43m"
#define gBLU "\x1B[44m"
#define gMAG "\x1B[45m"
#define gCYN "\x1B[46m"
#define gWHT "\x1B[47m"

// TYPOGRAPHY

#define Strikethrough "\x1B[9m"
#define Underlined "\x1B[4m"
#define Italic "\x1B[3m"
#define Faint "\x1B[2m"
#define BOLD "\x1B[1m"
// #define mainPlayer "❌"
#define computer "⚪"

// reset foreground and background to normal colours
#define RESET "\x1B[0m"

// TODO ALL MAIN VARIBLES
char gameArea[3][3];
const int mainPlayer[5] = "❌";

//! ALL MAIN FUNCTIONS SEE DOWN BELOW
void drew();
int field();
void resetArea();
void checkWinner(char);
    int winner[];

int main()
{

    // drew();
    // resetArea();
    printf("%c", mainPlayer);
    // checkWinner(winner);
}

//? DREWING THE LINES
void drew()
{
    // system("clear");
    printf(GRN BOLD "\n\t|\t|\t" RESET);
    printf(GRN BOLD "\n\t|\t|\t" RESET);
    printf(GRN BOLD "\n--------|-------|-------" RESET);
    printf(GRN BOLD "\n\t|\t|\t" RESET);
    printf(GRN BOLD "\n\t|\t|\t" RESET);
    printf(GRN BOLD "\n--------|-------|-------" RESET);
    printf(GRN BOLD "\n\t|\t|\t" RESET);
    printf(GRN BOLD "\n\t|\t|\t\n\n" RESET);
}

//? RESET THE AREA FOR NEW GAME
void resetArea()
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            gameArea[i][j] = ' ';
        }
    }
}

//? CHECK ALL field FILLED OR NOT
int checkField()
{
    int field = 9;
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (gameArea[i][j] != ' ')
            {
                field--;
            }
        }
    }
    return field;
}

//? CHECK THE WINNER
void checkWinner(char winner)
{
    if (winner == mainPlayer)
    {
        printf(YEL Underlined BOLD "👑 Hey, Nice plyed you win\n\n" RESET);
    }
    else if (winner == computer)
    {
        printf(gRED Underlined BOLD "😝 So sad,Try next time \n\n" RESET);
    }
    else
    {
        printf(CYN Underlined BOLD "😞 It's a Tie!, What a shame\n\n" RESET);
    }
}