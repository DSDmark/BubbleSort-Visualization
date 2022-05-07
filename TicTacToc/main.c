// usr/bin/clang "$0" && exec ./a.out "$@"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

//* Font code colours
#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define BLU "\x1B[34m"
#define MAG "\x1B[35m"
#define CYN "\x1B[36m"
#define WHT "\x1B[37m"
//* back ground code colours
#define gRED "\x1B[41m"
#define gGRN "\x1B[42m"
#define gYEL "\x1B[43m"
#define gBLU "\x1B[44m"
#define gMAG "\x1B[45m"
#define gCYN "\x1B[46m"
#define gWHT "\x1B[47m"

#define mainPlayer "❌\t"
#define computer "⚪\t"
//* TYPOGRAPHY

#define Strikethrough "\x1B[9m"
#define Underlined "\x1B[4m"
#define Italic "\x1B[3m"
#define Faint "\x1B[2m"
#define BOLD "\x1B[1m"

//* reset foreground and background to normal colours
#define RESET "\x1B[0m"

// TODO ALL MAIN VARIBLES
char *gameArea[9];
char *checkSpace = "\t";
char *winner;

//! ALL MAIN FUNCTIONS SEE DOWN BELOW
void drew(void);
int field(void);
void resetArea(void);
void checkWinner(char *);
void userInput(void);
void autoPlayer(void);
void validate(void);

//! STATE EXCUTIONS HERE
int main()
{
    validate();
}

//!IMPORTANT FUNCTION 
 void validate(){

     resetArea();

     if (checkField() != 0 && winner == " ")
     {
         drew();
         userInput();
         autoPlayer();
         if ()
         {
             /* code */
         }
         
     }
 }


//? DREWING THE LINES
void drew()
{
    system("clear");
    printf(GRN BOLD "\n\t|\t|\t" RESET);
    printf(GRN BOLD "\n  %s| %s| %s" RESET, gameArea[0], gameArea[1], gameArea[2]);
    printf(GRN BOLD "\n--------|-------|-------" RESET);
    printf(GRN BOLD "\n\t|\t|\t" RESET);
    printf(GRN BOLD "\n%s|%s|%s" RESET, gameArea[3], gameArea[4], gameArea[5]);
    printf(GRN BOLD "\n--------|-------|-------" RESET);
    printf(GRN BOLD "\n\t|\t|\t" RESET);
    printf(GRN BOLD "\n  %s| %s|%s\n\n" RESET, gameArea[6], gameArea[7], gameArea[8]);
}

//? RESET THE AREA FOR NEW GAME
void resetArea()
{
    int i, j;
    for (i = 0; i < 9; i++)
        gameArea[i] = "\t";
}

//? CHECK ALL field FILLED OR NOT
int checkField()
{
    int field = 9;
    int i, j;
    for (i = 0; i < 9; i++)
    {
        if (gameArea[i] != checkSpace)
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
        printf(BLU BOLD Underlined "What your N0.#(1-9)❔:" RESET);
        scanf("%d", &x);
        x--;

        // TODO VALIDET THE INPUT FIELD
        if (0 > x)
        {
            printf(Strikethrough gRED GRN "🤠 Hey boy, Enter a valid input ❕" RESET);
            printf("\n");
        }

        //* SAVE THE INPUT
        if (gameArea[x] != checkSpace)
        {
            printf(BOLD Underlined YEL "\nOopps..🚯 Wrong move bro..\n" RESET);
            printf("\n");
        }
        else
        {
            gameArea[x] = mainPlayer;
            break;
        }
    } while (gameArea[x] != checkSpace);
}

//? AUTO PLAYER FOR 0
void autoPlayer(){
    int x, y;
    srand(time(0));

    if (checkField() > 0)
    {
        do
        {
            x = (rand() % 9) + 1;
        } while (gameArea[x] != checkSpace);
        gameArea[x] = computer;
    }
    }