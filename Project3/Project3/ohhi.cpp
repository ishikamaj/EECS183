/**
 * ohhi.cpp
 * Project UID 5557cbe19b6ff413629a3743c503275413233136
 *
 * EECS 183
 * Project 3: 0h h1
 * Fall 2020
 *
 * Ishika Majumder
 * ishika@umich.edu
 *
 * This project replicates the board game Oh h1, a sudoku-like puzzle game. 
   Users are able to read, check, solve, and play basic instances of Oh h1.
 */

#include <iostream>
#include <cctype>
#include "utility.h"
#include "ohhi.h"

/**
 * --------------------------------------------------------
 * ---------- UTILITY FUNCTIONS ---------------------------
 * --------------------------------------------------------
 */

int count_unknown_squares(const int board[MAX_SIZE][MAX_SIZE], int size) {
    int count = 0;
    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            if (board[row][col] == UNKNOWN) {
                //counts every unknown square
                count++;
            }
        }
    }
    return count;
}


/**
 * --------------------------------------------------------
 * --------- VALIDITY CHECKING FUNCTIONS ------------------
 * --------------------------------------------------------
 */

bool row_has_no_threes_of_color(const int board[MAX_SIZE][MAX_SIZE],
                                int size,
                                int row,
                                int color) {
    for (int col = 0; col < size - 2; ++col) {
        //makes sure the neighboring 2 elements are not the same
        if (board[row][col] == color &&
            board[row][col + 1] == color &&
            board[row][col + 2] == color) {
            return false;
        }
    }
    return true;
}

bool col_has_no_threes_of_color(const int board[MAX_SIZE][MAX_SIZE],
                                int size,
                                int col,
                                int color) {
    for (int row = 0; row < size - 2; ++row) {
        //makes sure the neighboring 2 elements are not the same
        if (board[row][col] == color &&
            board[row + 1][col] == color &&
            board[row + 2][col] == color) {
            return false;
        }
    }
    return true;
}

bool board_has_no_threes(const int board[MAX_SIZE][MAX_SIZE], int size) {

    bool noThrees;
    for (int i = 0; i <= size; i++) {
        //checks both colors throughout row
        if ((row_has_no_threes_of_color(board, size, i, BLUE)) && 
            (row_has_no_threes_of_color(board, size, i, RED))) {
            noThrees = true;
        }
        else {
            return false;
        }
    }
    for (int j = 0; j <= size; j++) {
        //checks both colors throughout col
        if ((col_has_no_threes_of_color(board, size, j, BLUE)) &&
            (col_has_no_threes_of_color(board, size, j, RED))) {
            noThrees = true;
        }
        else {
            return false;
        }
    }
    return noThrees;
}

bool rows_are_different(const int board[MAX_SIZE][MAX_SIZE],
                        int size,
                        int row1,
                        int row2) {

    //if there is an unknown element, automatically returns true
    for (int i = 0; i < size; ++i) {
        if (board[row1][i] == UNKNOWN || board[row2][i] == UNKNOWN) {
            return true;
        }
    }

    int sameCount = 0;
    for (int j = 0; j < size; ++j) {
        //counts to see how many elements are in common 
        //between rows
        if (board[row1][j] == board[row2][j]) {
            sameCount++;
        }
    }
    //if they are identical, return false
    if (sameCount == size) {
        return false;
    }
    else {
        return true;
    }
}

bool cols_are_different(const int board[MAX_SIZE][MAX_SIZE],
                        int size,
                        int col1,
                        int col2) {
    //if there is an unknown element, automatically returns true
    for (int i = 0; i < size; ++i) {
        if (board[i][col1] == UNKNOWN || board[i][col2] == UNKNOWN) {
            return true;
        }
    }

    int sameCount = 0;
    for (int j = 0; j < size; ++j) {
        //counts to see how many elements are in common 
        //between columns
        if (board[j][col1] == board[j][col2]) {
            sameCount++;
        }
    }

    //if they are identical, return false
    if (sameCount == size) {
        return false;
    }
    else {
        return true;
    }
}

bool board_has_no_duplicates(const int board[MAX_SIZE][MAX_SIZE], int size) {
    bool noDups;

    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (rows_are_different(board, size, i, j)) {
                noDups = true;
            }
            //if rows aren't different, return false
            else {
                return false;
            }
        }
    }

    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (cols_are_different(board, size, i, j)) {
                noDups = true;
            }
            //if columns aren't different, return false
            else {
                return false;
            }
        }
    }
    
    return noDups;
}


/**
 * --------------------------------------------------------
 * ---------- SOLVING FUNCTIONS ---------------------------
 * --------------------------------------------------------
 */

void solve_three_in_a_row(int board[MAX_SIZE][MAX_SIZE],
                          int size,
                          int row,
                          bool announce) {
    
    //goes over row only once
    for (int col = 0; col < size - 2; col++) {
        //if current element is same as next element and they're not unknown
        if (board[row][col] == board[row][col + 1] 
            && board[row][col] != UNKNOWN) {
            //make sure there is an empty space to mark the opposite color
            if (board[row][col + 2] == UNKNOWN) {
                //if it's 1st col, only need to mark 1 square, rather than 2
                if (col == 0) {
                    mark_square_as(board, size, row, col + 2, 
                        opposite_color(board[row][col]), announce);
                }
                else {
                    //make sure there is empty space to mark opposite color
                    if (board[row][col - 1] == UNKNOWN) {
                        mark_square_as(board, size, row, col - 1, 
                            opposite_color(board[row][col]), announce);
                    }
                    mark_square_as(board, size, row, col + 2, 
                        opposite_color(board[row][col]), announce);
                }
            }
        }
        //if 'element' then 'unknown' then 'same element' sequence  is true
        if (board[row][col] == board[row][col + 2] 
            && board[row][col] != UNKNOWN && board[row][col + 1] == UNKNOWN) {
            mark_square_as(board, size, row, col + 1, 
                opposite_color(board[row][col]), announce);
        }
        //accounts for the cols that are not iterated through in the for loop
        if (col == size - 3) {
            //check if last 2 elements are the same and they're not unknown
            if (board[row][col + 1] == board[row][col + 2] 
                && board[row][col + 1] != UNKNOWN) {
                //make sure there is empty space to mark opposite color
                if (board[row][col] == UNKNOWN) {
                    mark_square_as(board, size, row, col, 
                        opposite_color(board[row][col + 1]), announce);
                }
            }
        }
    }

}

void solve_three_in_a_column(int board[MAX_SIZE][MAX_SIZE],
                             int size,
                             int col,
                             bool announce) {
    //goes over col only once
    for (int row = 0; row < size - 2; row++) {
        //if current element is same as next element and they're not unknown
        if (board[row][col] == board[row + 1][col] 
            && board[row][col] != UNKNOWN) {
            //make sure there is an empty space to mark the opposite color
            if (board[row + 2][col] == UNKNOWN) {
                //if it's 1st row, only need to mark 1 square, rather than 2
                if (row == 0) {
                    mark_square_as(board, size, row + 2, col, 
                        opposite_color(board[row][col]), announce);
                }
                else {
                    //make sure there is empty space to mark opposite color
                    if (board[row - 1][col] == UNKNOWN) {
                        mark_square_as(board, size, row - 1, col, 
                            opposite_color(board[row][col]), announce);
                    }
                    mark_square_as(board, size, row + 2, col, 
                        opposite_color(board[row][col]), announce);
                }
            }
        }
        //if 'element' then 'unknown' then 'same element' sequence  is true
        if (board[row][col] == board[row + 2][col] && 
            board[row][col] != UNKNOWN && board[row + 1][col] == UNKNOWN) {
            mark_square_as(board, size, row + 1, col, 
                opposite_color(board[row][col]), announce);
        }
        //accounts for the rows that are not iterated through in the for loop
        if (row == size - 3) {
            //check if last 2 elements are the same and they're not unknown
            if (board[row + 1][col] == board[row + 2][col] && 
                board[row + 1][col] != UNKNOWN) {
                //make sure there is empty space to mark opposite color
                if (board[row][col] == UNKNOWN) {
                    mark_square_as(board, size, row, col, 
                        opposite_color(board[row + 1][col]), announce);
                }
            }
        }
    }
}


void solve_balance_row(int board[MAX_SIZE][MAX_SIZE],
                       int size,
                       int row,
                       bool announce) {
    int redCount = 0;
    int blueCount = 0;
    for (int col = 0; col < size; col++) {
        //counts number of reds in row
        if (board[row][col] == RED) {
            redCount++;
        }
        //counts number of blues in row
        else if (board[row][col] == BLUE) {
            blueCount++;
        }
    }

    //if half the row is red, mark the unknowns the opposite color
    if (redCount == size / 2) {
        for (int cols = 0; cols < size; cols++) {
            if (board[row][cols] == UNKNOWN) {
                mark_square_as(board, size, row, cols, 
                    opposite_color(RED), announce);
            }
        }
    }
    //if half the row is blue, mark the unknowns the opposite color
    else if (blueCount == size / 2) {
        for (int cols = 0; cols < size; cols++) {
            if (board[row][cols] == UNKNOWN) {
                mark_square_as(board, size, row, cols, 
                    opposite_color(BLUE), announce);
            }
        }
    }
    
}

void solve_balance_column(int board[MAX_SIZE][MAX_SIZE],
                          int size,
                          int col,
                          bool announce) {
    int redCount = 0;
    int blueCount = 0;
    for (int row = 0; row < size; row++) {
        //counts number of reds in col
        if (board[row][col] == RED) {
            redCount++;
        }
        //counts number of blues in col
        else if (board[row][col] == BLUE) {
            blueCount++;
        }
    }

    //if half the col is red, mark the unknowns the opposite color
    if (redCount == size / 2) {
        for (int rows = 0; rows < size; rows++) {
            if (board[rows][col] == UNKNOWN) {
                mark_square_as(board, size, rows, col, BLUE, true);;
                announce = true;
            }
        }
    }
    //if half the col is blue, mark the unknowns the opposite color
    else if (blueCount == size / 2) {
        for (int rows = 0; rows < size; rows++) {
            if (board[rows][col] == UNKNOWN) {
                mark_square_as(board, size, rows, col, RED, true);;
                announce = true;
            }
        }
    }
}


/**
 * --------------------------------------------------------
 * ---------- GAMEPLAY FUNCTIONS --------------------------
 * --------------------------------------------------------
 */

bool board_is_solved(const int board[MAX_SIZE][MAX_SIZE], int size) {
    //no unknowns in a solved board
    if (count_unknown_squares(board, size) > 0) {
        return false;
    }

    //bnoard must be valid to be considered solved
    if (board_is_valid(board, size)) {
        return true;
    }
    
    return false;
}

bool check_valid_input(int size, int row_input, char col_input,
                       char color_char, int &row, int &col) {

    //row input must be between 1 and the size
    if (!(row_input > 0 && row_input <= size)) {
        cout << "Sorry, that's not a valid input." << endl;
        return false;
    }
    //changing the column input to be uppercase
    //then making sure the letter is within range
    char colIn = toupper(col_input);
    if (!(colIn >= 'A' && colIn <= ('A' + size - 1))) {
        cout << "Sorry, that's not a valid input." << endl;
        return false;
    }
    //changing the color input to be uppercase
    //then making sure it'sm one of the possible colors
    char colorCh = toupper(color_char);
    if (!(colorCh == 'X' || colorCh == 'O' || color_char == '-')) {
        cout << "Sorry, that's not a valid input." << endl;
        return false;
    }

    //converting column letter to a number and updated col
    for (int i = 0; i < size; i++) {
        if (colIn == static_cast<char>('A' + i)) {
            col = i;
        }
    }
    //updating row
    row = row_input - 1;
    return true;
}

bool check_valid_move(const int original_board[MAX_SIZE][MAX_SIZE],
                      const int current_board[MAX_SIZE][MAX_SIZE],
                      int size, int row, int col, int color) {

    //create copy of current board
    int copy[MAX_SIZE][MAX_SIZE];
    copy_board(current_board, copy, size);

    //assigning move wanted to copy board
    copy[row][col] = color;

    //can't overwrite original board
    if (original_board[row][col] != UNKNOWN) {
        cout << "Sorry, original squares cannot be changed." << endl;
        return false;
    }

    //board still has to be valid after playing the move
    if (!(board_is_valid(copy, size))) {
        cout << "Sorry, that move violates a rule." << endl;
        return false;
    }

    return true;
}
