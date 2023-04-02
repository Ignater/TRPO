#include "libmain/libmain.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>
#define Cs 100

int main()
{
    int c, kol, rep, game = 1;
    bool Fp = true;
    int mode;
    char f[10], s[10];
    srand(time(0));
    while (1) {
        mode = mode_select(mode, game);
        c = Cs;

        if (mode == 1) {
            getname(f, game);
            getname(s, game);
            printf("First mode: %s starts \n\n", f);
        } else {
            printf("PC mode:\n\n");
        }

        while (c > 0) {
            if (mode == 1) {
                if (Fp == true) {
                    kol = kolspichek(c, f, game);
                } else
                    kol = kolspichek(c, s, game);
            }
            if (mode == 2) {
                if (Fp == true) {
                    kol = kolspichek(c, "Your", game);
                } else {
                    kol = kolspichek1(c, game);
                }
            }

            c -= kol;
            Fp = !Fp;
        }
        if (mode == 1) {
            if (Fp == true) {
                printf("Winner is %s", f);
            } else {
                printf("Winner is %s", s);
            }
        }
        if (mode == 2) {
            if (Fp == true) {
                printf("Winner is You");
            } else {
                printf("Winner is PC");
            }
        }
        printf("\n\nYou wanna play again?\n1.Yes\n2.No\n");
        scanf("%d", &rep);
        printf("\n");
        if (rep == 1)
            continue;
        if (rep == 2) {
            printf("That was a good game\n");
            exit(0);
        }
    }
}
