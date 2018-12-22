#ifndef SUDOKU_SOLVER
# define SUDOKU_SOLVER

# include <stdio.h>
# include <stdlib.h>

typedef enum { false, true } bool;
int     read_map(FILE *sudoku_file, int map[9][9]);
void    print_map(int map[9][9]);
int     valid_map(int map[9][9]);
int     solve_map(int map[9][9], int lin, int col);

#endif // SUDOKU_SOLVER
