#include <ctest.h>
#include <libmain/libmain.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

CTEST(game_suite, input_check_1)
{
    int kol = 1;
    int game = 1;
    int c = 10;
    bool exp = true;
    bool res = input_check(kol, c, game);
    ASSERT_EQUAL(exp, res);
}

CTEST(game_suite, input_check_2)
{
    int c = 10;
    int kol = 0;
    int game = 0;
    bool exp = false;
    bool res = input_check(kol, c, game);
    ASSERT_EQUAL(exp, res);
}

CTEST(game_suite, mode_select)
{
    int mode = 1;
    int game = 0;
    bool exp = 0;
    bool res = mode_select(mode, game);
    ASSERT_EQUAL(exp, res);
}

CTEST(game_suite, kolspichek)
{
    int c = 5;
    int game = 0;
    int exp = 1;
    int kol = kolspichek(c, "Your", game);
    int res = kol;
    ASSERT_EQUAL(exp, res);
}

CTEST(game_suite, kolspichek1)
{
    int c = 5;
    int game = 0;
    bool exp = true;
    bool res = kolspichek1(c, game);
    ASSERT_EQUAL(exp, res);
}
