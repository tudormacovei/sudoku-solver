#include "sudoku_solver.h"

int         main()
{
    FILE    *sudoku_file;
    int     map[9][9];

    sudoku_file = NULL;
    if (!read_map(sudoku_file, map))
        return 1;
    if (solve_map(map, 0, -1))
        print_map(map);
    else
        printf("Input file is not a solvable sudoku.");
    return 0;
}
