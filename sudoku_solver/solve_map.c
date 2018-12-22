#include "sudoku_solver.h"

int         valid_line(int map[9][9], int lin)
{
    int     i;
    bool    digits[10] = {false};

    for (i = 0; i < 9; i++)
            if (map[lin][i] != 0 && digits[map[lin][i]] == true)
                return 0;
            else
                digits[map[lin][i]] = true;
    return 1;
}

int         valid_column(int map[9][9], int col)
{
    int     i;
    bool    digits[10] = {false};

    for (i = 0; i < 9; i++)
            if (map[i][col] != 0 && digits[map[i][col]] == true)
                return 0;
            else
                digits[map[i][col]] = true;
    return 1;
}

void        square_coords(int square, int *lin, int *col)
{
    *lin = (square / 3) * 3;
    *col = (square % 3) * 3;
}

int         valid_square(int map[9][9], int square)
{
    /* coordinates of the top-right corner of the square */
    int     lin;
    int     col;
    int     i;
    int     j;
    bool    digits[10] = {false};

    square_coords(square, &lin, &col);
    //printf("top-left coordinates of square: \n %d, %d \n", i, j);
    for (i = lin; i < lin + 3; i++)
        for (j = col; j < col + 3; j++)
            if (map[i][j] != 0 && digits[map[i][j]] == true)
                return 0;
            else
                digits[map[i][j]] = true;
    return 1;
}

int         valid_map(int map[9][9])
{
    int     i;

    for (i = 0; i < 9; i++)
    {
        if (!valid_line(map, i) || !valid_column(map, i)
            || !valid_square(map, i))
            return 0;
    }
    return 1;
}

void        next_position(int *lin, int *col)
{
    if (*col == 8)
    {
        *col = 0;
        *lin = *lin + 1;
    }
    else
        *col = *col + 1;
}

int         solve_map(int map[9][9], int lin, int col)
{
    int     digit;

    /* solution found */
    next_position(&lin, &col);
    if (lin == 9)
        return 1;
    if (map[lin][col] == 0)
    {
        for (digit = 1; digit <= 9; digit++)
        {
            map[lin][col] = digit;
            if (valid_map(map) && solve_map(map, lin, col))
                return 1;
        }
        /* all solutions faild for this state of map[][] */
        map[lin][col] = 0;
        return 0;
    }
    else
        return solve_map(map, lin, col);
}
