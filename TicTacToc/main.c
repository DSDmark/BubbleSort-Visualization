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
#define mainPlayer "❌"
#define computer "⚪"

// reset foreground and background to normal colours
#define RESET "\x1B[0m"

// TODO ALL MAIN VARIBLES
char gameArea[3][3];

//! ALL MAIN FUNCTIONS SEE DOWN BELOW
void drew();
// void resetBoard();

int main()
{

    // resetBoard();
    // printf(RED "dfd" RESET);
    drew();
}

//? DREWING THE LINES
void drew()
{
    system("clear");
    printf(GRN BOLD "\n\t|\t|\t" RESET);
    printf(GRN BOLD "\n\t|\t|\t" RESET);
    printf(GRN BOLD "\n--------|-------|-------" RESET);
    printf(GRN BOLD "\n\t|\t|\t" RESET);
    printf(GRN BOLD "\n\t|\t|\t" RESET);
    printf(GRN BOLD "\n--------|-------|-------" RESET);
    printf(GRN BOLD "\n\t|\t|\t" RESET);
    printf(GRN BOLD "\n\t|\t|\t\n\n" RESET);
}
