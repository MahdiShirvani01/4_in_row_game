/* Mehdi Shirvani
    student number : 40012358021*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #include <conio.h>
#include <stdbool.h>
#include <ctype.h>
#include <windows.h>
#define Table_Line 8
#define Table_Column 8

int Color_func(const int foreground);                           // function to have colored piece
int Menu();                                                     // main function to start
const char *Show(char[], char[], char[]);                       // print every thing is needed
bool TurnFunc(char[], int, char[], char[], int *);              // columns selection
int Check_Vertical(char[], char[]);                             // check winner in vertical
int Check_Horizental(char[], char[]);                           // check winner in horizental
int Check_Diagonal(char[], char[]);                             // check winner in diagonal
int Scores(char[], char[], char[], int *, int *, int *, int *); // have Scores of game in playin
void Guied();                                                   // Guied
void produce();                                                 // producer Scores
void Exit();                                                    // Exit from the game

int main() // main
{
    Menu();

    return 0;
}

typedef CONSOLE_SCREEN_BUFFER_INFO BufferInfo;

int Color_func(const int foreground) // function to have colored piece
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    BufferInfo bufferInfo;

    if (!GetConsoleScreenBufferInfo(consoleHandle, &bufferInfo))

        return 0;

    WORD color = (bufferInfo.wAttributes & 0xF0) + (foreground & 0x0F);

    SetConsoleTextAttribute(consoleHandle, color);

    return 1;
}

bool TurnFunc(char table[Table_Column * Table_Line], int player_turn, char Color_List[], char color_table[Table_Column * Table_Line], int *check)
{
    int col, line;
    char a = 219; // to put charater 219 in a array
    while (true)
    {
        if (player_turn == 0) // show player turn message
        {
            switch (Color_List[0])
            {
            case 0: // red player 1
                printf("To save press 0 and to exit press 9\n");

                printf("player 1 (");
                Color_func(4);
                printf("%c%c%c", a, a, a);
                Color_func(7);
                printf(") enter your number : ");
                break;
            case 1: // yellow player 1
                printf("To save press 0 and to exit press 9\n");
                printf("player 1 (");
                Color_func(6);
                printf("%c%c%c", a, a, a);
                Color_func(7);
                printf(") enter your number : ");

                break;
            case 2: // green player 1
                printf("To save press 0 and to exit press 9\n");

                printf("player 1 (");
                Color_func(18);
                printf("%c%c%c", a, a, a);
                Color_func(7);
                printf(") enter your number : ");

                break;
            case 3: // blue player 1
                printf("To save press 0 and to exit press 9\n");
                printf("player 1 (");
                Color_func(3);
                printf("%c%c%c", a, a, a);
                Color_func(7);
                printf(") enter your number : ");

                break;
            default:
                break;
            }
        }

        if (player_turn == 1)
        {
            switch (Color_List[1])
            {
            case 0: // red player 2
                printf("To save press 0 and to exit press 9\n");
                printf("player 2 (");
                Color_func(4);
                printf("%c%c%c", a, a, a);
                Color_func(7);
                printf(") enter your number : ");

                break;
            case 1: // yellow player 2
                printf("To save press 0 and to exit press 9\n");
                printf("player 2 (");
                Color_func(6);
                printf("%c%c%c", a, a, a);
                Color_func(7);
                printf(") enter your number : ");

                break;
            case 2: // green player 2
                printf("To save press 0 and to exit press 9\n");
                printf("player 2 (");
                Color_func(18);
                printf("%c%c%c", a, a, a);
                Color_func(7);
                printf(") enter your number : ");

                break;

            case 3: // blue player 2
                printf("To save press 0 and to exit press 9\n");
                printf("player 2 (");
                Color_func(3);
                printf("%c%c%c", a, a, a);
                Color_func(7);
                printf(") enter your number : ");

                break;
            default:
                break;
            }
        }
        scanf("%d", &col); // gettin num to put char 219 in array or save game or exit from the game is running

        if (col == 0) // save game
        {
            *check = 0;
            return false;
        }
        if (col == 9) // exit from the game is running
        {
            *check = 2;
            return false;
        }

        while (false != (col > 8) || (col < 1)) // limitation for input
        {
            while (getchar() != '\n')
                ;
            printf("your choose is not in range !, try again : ");
            scanf("%d", &col);
        }
        --col;
        for (line = Table_Line - 1; line >= 0; line--) // put char 219 in the table(a array to save choice) and put color num in the color_table(a array to save colors)
        {
            if (table[Table_Column * line + col] == ' ')
            {
                table[Table_Column * line + col] = 219;
                if (player_turn == 1)
                    color_table[Table_Column * line + col] = Color_List[1];
                if (player_turn == 0)
                    color_table[Table_Column * line + col] = Color_List[0];
                return true;
            }
        }
        *check = 1;
        return false;
    }
}

const char *Show(char table[Table_Column * Table_Line], char Color_List[], char color_table[Table_Column * Table_Line])
{
    int line, col, flag;

    puts("\n+-------------------------------+");

    for (line = 0; line < Table_Line; line++)
    {
        for (col = 0; col < Table_Column; col++)
        {
            flag = 1;
            if ((table[Table_Line * line + col] != ' ') && color_table[Table_Line * line + col] == 0 && flag == 1) // print red char 219
            {
                printf("|");
                Color_func(4);
                printf("%c%c%c", table[Table_Line * line + col], table[Table_Line * line + col], table[Table_Line * line + col]);
                Color_func(7);
                flag = 0;
            }
            if ((table[Table_Line * line + col] != ' ') && color_table[Table_Line * line + col] == 1 && flag == 1) // print yellow char 219
            {
                printf("|");
                Color_func(6);
                printf("%c%c%c", table[Table_Line * line + col], table[Table_Line * line + col], table[Table_Line * line + col]);
                Color_func(7);
                flag = 0;
            }
            if ((table[Table_Line * line + col] != ' ') && color_table[Table_Line * line + col] == 2 && flag == 1) // print green char 219
            {
                printf("|");
                Color_func(18);
                printf("%c%c%c", table[Table_Line * line + col], table[Table_Line * line + col], table[Table_Line * line + col]);
                Color_func(7);
                flag = 0;
            }
            if ((table[Table_Line * line + col] != ' ') && color_table[Table_Line * line + col] == 3 && flag == 1) // print blue char 219
            {
                printf("|");
                Color_func(3);
                printf("%c%c%c", table[Table_Line * line + col], table[Table_Line * line + col], table[Table_Line * line + col]);
                Color_func(7);
                flag = 0;
            }
            if (table[Table_Line * line + col] == ' ') // if table is null print ' '
                printf("| %c ", table[Table_Line * line + col]);
        }
        puts("|");
        puts("+-------------------------------+");
    }
    puts("  1   2   3   4   5   6   7   8\n");
}

int Check_Vertical(char color_table[Table_Column * Table_Line], char Color_List[]) // check all positions in vertical
{
    for (size_t line = (Table_Line - 1); line >= (Table_Line - 3); line--)
    {
        for (size_t col = 0; col < Table_Column; col++)
        {
            if ((color_table[Table_Column * line + col] == Color_List[0]) && (color_table[Table_Column * (line - 1) + col] == Color_List[0]) && (color_table[Table_Column * (line - 2) + col] == Color_List[0]) && (color_table[Table_Column * (line - 3) + col] == Color_List[0]))
            {
                return 1;
            }
            if ((color_table[Table_Column * line + col] == Color_List[1]) && (color_table[Table_Column * (line - 1) + col] == Color_List[1]) && (color_table[Table_Column * (line - 2) + col] == Color_List[1]) && (color_table[Table_Column * (line - 3) + col] == Color_List[1]))
            {
                return 2;
            }
        }
    }
    return 0;
}

int Check_Horizental(char color_table[Table_Column * Table_Line], char Color_List[]) // check all positions in horizental
{

    for (size_t line = 0; line < Table_Column; line++)
    {
        for (size_t col = 0; col < Table_Column - 3; col++)
        {
            if ((color_table[Table_Column * line + col] == Color_List[0]) && (color_table[Table_Column * line + col + 1] == Color_List[0]) && (color_table[Table_Column * line + col + 2] == Color_List[0]) && (color_table[Table_Column * line + col + 3] == Color_List[0]))
            {
                return 1;
            }
            if ((color_table[Table_Column * line + col] == Color_List[1]) && (color_table[Table_Column * line + col + 1] == Color_List[1]) && (color_table[Table_Column * line + col + 2] == Color_List[1]) && (color_table[Table_Column * line + col + 3] == Color_List[1]))
            {
                return 2;
            }
        }
    }
    return 0;
}

int Check_Diagonal(char color_table[Table_Column * Table_Line], char Color_List[]) // check all positions in diagonal
{
    for (size_t line = Table_Line - 1; line >= Table_Line - 5; line--)
    {
        for (size_t col = Table_Column - 1; col >= Table_Column - 5; col--) // check from index 7 to 3
        {
            if ((color_table[Table_Column * line + col] == Color_List[0]) && (color_table[Table_Column * (line - 1) + (col - 1)] == Color_List[0]) && (color_table[Table_Column * (line - 2) + (col - 2)] == Color_List[0]) && (color_table[Table_Column * (line - 3) + (col - 3)] == Color_List[0]))
            {
                return 1;
            }
            if ((color_table[Table_Column * line + col] == Color_List[1]) && (color_table[Table_Column * (line - 1) + (col - 1)] == Color_List[1]) && (color_table[Table_Column * (line - 2) + (col - 2)] == Color_List[1]) && (color_table[Table_Column * (line - 3) + (col - 3)] == Color_List[1]))
            {
                return 2;
            }
        }
        for (size_t col = 0; col < Table_Column - 3; col++) // check from index 0 to 4
        {
            if ((color_table[Table_Column * line + col] == Color_List[0]) && (color_table[Table_Column * (line - 1) + (col + 1)] == Color_List[0]) && (color_table[Table_Column * (line - 2) + (col + 2)] == Color_List[0]) && (color_table[Table_Column * (line - 3) + (col + 3)] == Color_List[0]))
            {
                return 1;
            }
            if ((color_table[Table_Column * line + col] == Color_List[1]) && (color_table[Table_Column * (line - 1) + (col + 1)] == Color_List[1]) && (color_table[Table_Column * (line - 2) + (col + 2)] == Color_List[1]) && (color_table[Table_Column * (line - 3) + (col + 3)] == Color_List[1]))
            {
                return 2;
            }
        }
    }
    return 0;
}

int Scores(char table[Table_Column * Table_Line], char color_table[Table_Column * Table_Line], char Color_List[], int *count_1, int *count_2, int *turn, int *tie)
{
    int flag_2 = 0; // if one of conditions true, don't check another

    if (Check_Vertical(color_table, Color_List) == 1 && flag_2 == 0) // if player 1 win in vertical, have 1 point and here save. three times they can tie or win
    {
        printf("player 1 you win\n");
        (*count_1)++;
        printf("Score(player 1, player 2) : %d  %d\n", *count_1, *count_2);
        flag_2 = 1;
        *turn = -1;
        if (*count_1 != 3)
            printf("OK, start again !\n");
        Show(table, Color_List, color_table);
    }

    if (Check_Vertical(color_table, Color_List) == 2 && flag_2 == 0)
    {
        printf("player 2 you win\n");
        (*count_2)++;
        printf("Score(player 1, player 2) : %d  %d\n", *count_1, *count_2);
        flag_2 = 1;
        *turn = -1;
        if (*count_2 != 3)
            printf("OK, start again !\n");
        Show(table, Color_List, color_table);
    }

    if (Check_Horizental(color_table, Color_List) == 1 && flag_2 == 0)
    {
        printf("player 1 you win\n");
        (*count_1)++;
        printf("Score(player 1, player 2) : %d  %d\n", *count_1, *count_2);
        flag_2 = 1;
        *turn = -1;
        if (*count_1 != 3)
            printf("OK, start again !\n");
        Show(table, Color_List, color_table);
    }

    if (Check_Horizental(color_table, Color_List) == 2 && flag_2 == 0)
    {
        printf("player 2 you win\n");
        (*count_2)++;
        printf("Score(player 1, player 2) : %d  %d\n", *count_1, *count_2);
        flag_2 = 1;
        *turn = -1;
        if (*count_2 != 3)
            printf("OK, start again !\n");
        Show(table, Color_List, color_table);
    }

    if (Check_Diagonal(color_table, Color_List) == 1 && flag_2 == 0)
    {
        printf("player 1 you win\n");
        (*count_1)++;
        printf("Score(player 1, player 2) : %d  %d\n", *count_1, *count_2);
        flag_2 = 1;
        *turn = -1;
        if (*count_1 != 3)
            printf("OK, start again !\n");
        Show(table, Color_List, color_table);
    }

    if (Check_Diagonal(color_table, Color_List) == 2 && flag_2 == 0)
    {
        printf("player 2 you win\n");
        (*count_2)++;
        printf("Score(player 1, player 2) : %d  %d\n", *count_1, *count_2);
        flag_2 = 1;
        *turn = -1;
        if (*count_2 != 3)
            printf("OK, start again !\n");
        Show(table, Color_List, color_table);
    }

    if (Check_Vertical(color_table, Color_List) == Check_Horizental(color_table, Color_List) && (Check_Vertical(color_table, Color_List) == Check_Diagonal(color_table, Color_List)) && *turn == 63) // equal points
    {
        (*tie)++;
        printf("it's tie, try again\n");
        printf("Score(player 1, player 2) : %d  %d\n", *count_1, *count_2);
        *turn = -1;
        if (*tie != 3)
            Show(table, Color_List, color_table);
    }
    if ((*count_1 == 3) || (*count_2 == 3) || (*tie == 3))
        return 0;
    return 1;
}
void Guied()
{
    printf("               >>> Guied <<<              \n");
    printf("1. Rules\n");
    printf("2. Scores\n");
    printf("3. How to play\n\n");
    Color_func(6);
    printf("Rules :");
    Color_func(7);
    printf("\nThere are two players to play, each of them must have own color.\nIf in the table, each of the players can put four pieces in a row\nhorizontally, vertically or diagonally, first time, it's winner.\n");
    printf("You can put you pieces any way you like.\n\n");
    Color_func(6);
    printf("Scores :");
    Color_func(7);
    printf("\nIn this game, each victory has one point and someone reaches three\npoints first, will win the game, if their scores tie in three rounds,\nwe willnot have a winner\n\n");
    Color_func(6);
    printf("How to play :");
    Color_func(7);
    printf("\nEach player's turn, who has to choose one of th eight columns so that\nhis piece is placed in the lowest house of that column and continues in\nthe same way so that he can choose his four pieces to win. It is natural\nthat the opponent should not let him win. and try to win the game.\n\n\n");
}
void produce()
{
    printf("\nProducer : Mehdi Shirvani\n");
    printf("User Number : 40012358021\n");
    printf("User code : 3861365855\n");
    printf("Finished time : 7/21/2022\n");
    printf("Many thanks to the adopters of this game\n");
    printf("Goodby\n");
}
int Menu()
{
    while (true) // main menu to start game
    {
        printf("\n\nHi guys, welcome to >>>  Connect Four  <<<\n\n"); // after each entry , repeat
        int temp, flag = 0;

        printf("1. New Game \n");
        printf("2. Clear Save History \n");
        printf("3. Guied \n");
        printf("4. Producer \n");
        printf("5. Exit \n");
        printf("Enter a num to start : ");
        scanf("%d", &temp);

        if (temp == 1)
        {
            char table[Table_Column * Table_Line];       // array to put character 219 (nut)
            char color_table[Table_Column * Table_Line]; // array to put colors

            memset(table, ' ', Table_Column * Table_Line);      // empty the table
            memset(color_table, -1, Table_Column * Table_Line); // empty the color_table

            int color_p_1, color_p_2, count_1 = 0, count_2 = 0, tie = 0, check = 1; // count_1 and count_2 : count victory of player1 and player 2, tie: count the numbers of tie
            char Color_List[2];                                                     // list of selective color

            printf("Every one can choose one color from < red(0), yellow(1), green(2), blue(3) >\n");
            printf("Playe 1 choose your color : ");
            scanf("%d", &color_p_1); // getting color of player 1

            while (false != (color_p_1 > 3) || (color_p_1 < 0)) // limitation on entry
            {
                while (getchar() != '\n')
                    ;
                printf("your choose is not in range !, try again : ");
                scanf("%d", &color_p_1);
            }

            printf("Playe 2 choose your color : ");
            scanf("%d", &color_p_2); // getting color of player 2

            while (false != (color_p_2 > 3) || (color_p_2 < 0)) // limitation on entry
            {
                while (getchar() != '\n')
                    ;
                printf("your choose is not in range !, try again : ");
                scanf("%d", &color_p_2);
            }

            Color_List[0] = color_p_1; // put players color in list of color
            Color_List[1] = color_p_2;

            while (Color_List[0] == Color_List[1]) // don't choose same color
            {
                printf("Player 2 you can't choose same color, choose again : ");
                scanf("%d", &color_p_2);
                Color_List[1] = color_p_2;
            }

            Show(table, Color_List, color_table);
            // int temp;
            for (size_t turn = 0; (turn < Table_Column * Table_Line); turn++) // start choice , 1 to 64 times
            {
                int flag_2 = 0;
                while (TurnFunc(table, turn % 2, Color_List, color_table, &check) == false) // turn % 2 choose which player's turn, and we have check to choose way(save, exit, ...)
                {
                    if (check == 1) // choose another column, because it's full
                    {
                        Show(table, Color_List, color_table);
                        printf("Colunm is full !, choose another colunm\n");
                    }
                    if (check == 0) // save
                    {
                        printf("your info saved.\n");
                        turn--;
                        FILE *fp;
                        fp = fopen("save_the_game", "w");
                        if (fp == NULL)
                        {
                            puts("Can't open file");
                        }
                        for (size_t line = 0; line < 8; line++)
                        {
                            for (size_t col = 0; col < 8; col++)
                            {
                                if (color_table[8 * line + col] == Color_List[0])
                                {
                                    fprintf(fp, "A ");
                                }
                                if (color_table[8 * line + col] == Color_List[1])
                                {
                                    fprintf(fp, "B ");
                                }
                                if (color_table[8 * line + col] == -1)
                                {
                                    fprintf(fp, "N ");
                                }
                            }
                            fputs("\n", fp);
                        }
                        fprintf(fp, "\nColors = {0: Red, 1: Yellow, 2: Green, 3: Blue\n");
                        fprintf(fp, "\nplayer 1 victories  : %d\n", count_1); // printf players information in file
                        fprintf(fp, "player 1 color : %d\n", color_p_1);
                        fprintf(fp, "player 2 victories  : %d\n", count_2);
                        fprintf(fp, "player 2 color : %d\n", color_p_2);
                        fclose(fp);

                        break;
                    }
                    if (check == 2) // exit from running game
                    {
                        printf("you exited\n");
                        turn = 64;
                        break;
                    }
                }

                Show(table, Color_List, color_table);

                if (Scores(table, color_table, Color_List, &count_1, &count_2, &turn, &tie) == 0)
                    break;
                if (turn == -1)
                {
                    memset(table, ' ', Table_Column * Table_Line);      // empty the table
                    memset(color_table, -1, Table_Column * Table_Line); // empty the color_table
                }
            }
            // the following conditions, determine the final winner
            if (count_1 == count_2)
            {
                printf("No winner, it's tie !!!\n");
            }

            if (count_1 > count_2)
            {
                printf("%s", "playre 1 you win the game \n");
            }

            if (count_2 > count_1)
            {
                printf("playre 2 you win the game \n");
            }
        }

        if (temp == 2) // clear your saved history
        {
            FILE *fp = fopen("save_the_game", "r");
            if (fp == NULL)
            {
                Color_func(4);
                printf("\nThere is no history !!\n");
                Color_func(7);
            }
            else
            {
                fclose(fp);
                remove("save_the_game");
                printf("\nDelete history was successful\n");
                fclose(fp);
            }
        }
        if (temp == 3) // print guied
        {
            Guied();
        }
        if (temp == 4) // print producer information
            produce();

        if (temp == 5) // exit from the game
            break;
    }
}