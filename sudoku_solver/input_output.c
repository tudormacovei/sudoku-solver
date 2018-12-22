#include "sudoku_solver.h"

int     read_map(FILE *sudoku_file, int map[9][9])
{
    int i;
    int j;

    sudoku_file = fopen("map.txt", "r");
    if (sudoku_file == NULL)
    {
        printf("Input file not found.");
        return 0;
    }
    for (i = 0; i < 9; i++)
        for (j = 0; j < 9; j++)
            fscanf(sudoku_file, "%d", &map[i][j]);
    if (!valid_map(map))
    {
        printf("Input file is not a solvable sudoku.");
        return 0;
    }
    fclose(sudoku_file);
    return 1;
}

void    print_map(int map[9][9])
{
    int i;
    int j;

    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
            printf("%d ", map[i][j]);
        printf("\n");
    }
}
