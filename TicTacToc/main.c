// usr/bin/clang "$0" && exec ./a.out "$@"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

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

#define mainPlayer "❌"
#define computer "⚪"
// TYPOGRAPHY

#define Strikethrough "\x1B[9m"
#define Underlined "\x1B[4m"
#define Italic "\x1B[3m"
#define Faint "\x1B[2m"
#define BOLD "\x1B[1m"

// reset foreground and background to normal colours
#define RESET "\x1B[0m"

// TODO ALL MAIN VARIBLES
char *gameArea[9];

//! ALL MAIN FUNCTIONS SEE DOWN BELOW
void drew(void);
int field(void);
void resetArea(void);
void checkWinner(char *);
void userInput(void);

char *winner;

int main()
{
    // winner = computer;
    // drew();
    resetArea();
    userInput();
    // gameArea[0] = computer;
    // printf("%s", gameArea[0]);
    for (int i = 0; i < 9; i++)
    {
        printf("%s", gameArea[i]);
    }

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
    for (i = 0; i < 9; i++)
        gameArea[i] = " ";
}

//? CHECK ALL field FILLED OR NOT
int checkField()
{
    int field = 9;
    int i, j;
    for (i = 0; i < 9; i++)
    {
        if (gameArea[i] != " ")
        {
            field--;
        }
    }
    return field;
}

//? CHECK THE WINNER
void checkWinner(char *winner)
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

//? TAKE INPUT FROM USER
void userInput()
{
    int x;
    do
    {
        if (x == ' ')
        {
            printf("What your N0.#(1-9)❔:");
            scanf("%d", &x);
            x--;
        }

        // TODO VALIDET THE INPUT FIELD
        if (!isdigit(x) || 0 < x || !(x == '\0'))
        {
            printf(Strikethrough gRED GRN "🤠Hey boy, Enter a valid input❗" RESET);
        }

        //* SAVE THE INPUT
        if (gameArea[x] != " ")
        {
            printf("Oopps..🚯 Wrong move bro..\n");
            x = ' ';
        }
        else
        {
            gameArea[x] = mainPlayer;
            x = ' ';
            break;
        }
    } while (gameArea[x] != " ");
}