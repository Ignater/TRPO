#include "libmain.h"
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int mode_select(int mode, int game)
{
    mode = 0;
    char str[16];
    if (game) {
        printf("\nChoose a mode: \n");
        printf("1. Let's play together\n");
        printf("2. Game with a computer\n");
        printf("\n");
        while (1) {
            fgets(str, 16, stdin);
            if (0x30 <= str[0] && str[0] <= 0x39) {
                mode = str[0] & 0x0F;
                if ((mode == 1) || (mode == 2)) {
                    break;
                } else {
                    printf("Error mode. Try again!\n");
                    continue;
                }
            } else {
                printf("Error mode.Try again!\n");
                continue;
            }
        }
    }
    return mode;
}

int input_check(int kol, int c, int game)
{
    bool flag;
    if ((kol >= 1) && (kol <= 10) && (kol <= c)) {
        flag = true;
    } else {
        if (game == 1) {
            printf("Incorrect. Try again!\n");
        }
        flag = false;
    }
    return flag;
}

void getname(char* name, int game)
{
    if (game) {
        printf("Enter a name: ");
        scanf("%s", name);
        printf("Hello, %s\n", name);
    }
}

int kolspichek(int c, const char* name, int game)
{
    bool flag;
    int kol = 1;
    if (game) {
        do {
            printf("%s turn. Current quantity: %d.\nEnter the number of "
                   "matches\n",
                   name,
                   c);
            bool test = scanf("%d", &kol);
            if (test == 0) {
                printf("Error\n");
                exit(0);
            }

            flag = input_check(kol, c, game);
        } while (!flag);
    }
    return kol;
}

int kolspichek1(int c, int game)
{
    int kol = rand() % 10 + 1;
    if (kol > c) {
        kol = c;
    }
    if (game) {
        printf("Computer Turn. I take %d spichek\n", kol);
    }
    return kol;
}
