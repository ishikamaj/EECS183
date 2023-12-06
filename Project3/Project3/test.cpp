/**
 * test.cpp
 * Project UID 5557cbe19b6ff413629a3743c503275413233136
 *
 * EECS 183
 * Project 3: 0h h1 Test Suite
 * Fall 2019
 *
 * Ishika Majumder
 * ishika@umich.edu
 *
 * This project replicates the board game Oh h1, a sudoku-like puzzle game. 
   Users are able to read, check, solve, and play basic instances of Oh h1.
 */

#include <iostream>
#include "utility.h"
#include "ohhi.h"

void test_count_unknown_squares();
void test_row_has_no_threes_of_color();
void test_col_has_no_threes_of_color();
void test_board_has_no_threes();
void test_solve_balance_row();
void test_solve_balance_column();
void test_rows_are_different();
void test_cols_are_different();
void test_board_has_no_duplicates();
void test_solve_three_in_a_row();
void test_solve_three_in_a_column();
void test_board_is_solved();
void test_check_valid_input();
void test_check_valid_move();

void startTests() {
    test_count_unknown_squares();

    test_row_has_no_threes_of_color();
    test_col_has_no_threes_of_color();
    test_board_has_no_threes();
    test_solve_balance_row();
    test_solve_balance_column();
    test_rows_are_different();
    test_cols_are_different();
    test_board_has_no_duplicates();
    test_solve_three_in_a_row();
    test_solve_three_in_a_column();
    test_board_is_solved();
    test_check_valid_input();
    test_check_valid_move();
}


void test_count_unknown_squares() {
    int board[MAX_SIZE][MAX_SIZE];

    cout << "\nNow testing: count_unknown_squares()" << endl;
    // test case 1
    string test_board_1[] = {"XOXO",
                             "--OO",
                             "---X",
                             "--O-"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << "Expected: 8, Actual: " << count_unknown_squares(board, size_1) << endl;


    // test case 2
    string test_board_2[] = { "X-O-",
                             "-OOO",
                             "XX-X",
                             "--XX" };
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << "Expected: 6, Actual: " << count_unknown_squares(board, size_2) << endl;

    // test case 3
    string test_board_3[] = { "X-O---",
                             "-OOOXX",
                             "XX-XXO",
                             "--XXOO",
                             "------",
                             "--OXOX" };
    int size_3 = 6;
    read_board_from_string(board, test_board_3, size_3);
    cout << "Expected: 16, Actual: " << count_unknown_squares(board, size_3) << endl;

    // test case 4
    string test_board_4[] = { "X-O-XX",
                             "-O--XX",
                             "OO---O",
                             "--X-OO",
                             "--XOX-",
                             "--O--X" };
    int size_4 = 6;
    read_board_from_string(board, test_board_4, size_4);
    cout << "Expected: 18, Actual: " << count_unknown_squares(board, size_4) << endl;

    // test case 5
    string test_board_5[] = { "------",
                             "-O-OOX",
                             "OOXX-O",
                             "O-X-OO",
                             "XOXOX-",
                             "--OXXX" };
    int size_5 = 6;
    read_board_from_string(board, test_board_5, size_5);
    cout << "Expected: 14, Actual: " << count_unknown_squares(board, size_5) << endl;
    
}

void test_row_has_no_threes_of_color() {
    int board[MAX_SIZE][MAX_SIZE];

    cout << "\nNow testing: row_has_no_threes_of_color()" << endl;

    string test_board_1[] = { "XXXX",
                             "OXXX",
                             "XXXX",
                             "OOOO" };
    int size_1 = 4;
    int row_1 = 2;
    read_board_from_string(board, test_board_1, size_1);
    // test case 1 
    cout << "Expected: 0, Actual: " << row_has_no_threes_of_color(board, size_1, row_1, RED) << endl;

    int row_2 = 3;
    // test case 2
    cout << "Expected: 0, Actual: " << row_has_no_threes_of_color(board, size_1, row_2, BLUE) << endl;

    int row_3 = 1;
    // test case 3
    cout << "Expected: 0, Actual: " << row_has_no_threes_of_color(board, size_1, row_3, RED) << endl;

    string test_board_2[] = { "XXXX--",
                             "X-X-OO",
                             "XX-XX-",
                             "OOO--O",
                             "-OOOX-",
                             "--XXX-"};
    int size_2 = 6;
    int row_4 = 2;
    read_board_from_string(board, test_board_2, size_2);
    // test case 4
    cout << "Expected: 1, Actual: " << row_has_no_threes_of_color(board, size_2, row_4, RED) << endl;

    int row_5 = 5;
    // test case 5
    cout << "Expected: 0, Actual: " << row_has_no_threes_of_color(board, size_2, row_5, RED) << endl;

}

void test_col_has_no_threes_of_color() {
    int board[MAX_SIZE][MAX_SIZE];

    cout << "\nNow testing: col_has_no_threes_of_color()" << endl;

    string test_board_1[] = { "XXXX",
                             "OXXO",
                             "XXXO",
                             "OOOO" };
    int size_1 = 4;
    int col_1 = 2;
    read_board_from_string(board, test_board_1, size_1);
    // test case 1 
    cout << "Expected: 0, Actual: " << col_has_no_threes_of_color(board, size_1, col_1, RED) << endl;

    int col_2 = 0;
    // test case 2
    cout << "Expected: 1, Actual: " << col_has_no_threes_of_color(board, size_1, col_2, RED) << endl;

    int col_3 = 3;
    // test case 3
    cout << "Expected: 0, Actual: " << col_has_no_threes_of_color(board, size_1, col_3, BLUE) << endl;

    string test_board_2[] = {"XXXX--",
                             "X-X-OO",
                             "XX-XXO",
                             "OOO--O",
                             "-OOOX-",
                             "--XXX-" };
    int size_2 = 6;
    int col_4 = 1;
    read_board_from_string(board, test_board_2, size_2);
    // test case 4
    cout << "Expected: 1, Actual: " << col_has_no_threes_of_color(board, size_2, col_4, BLUE) << endl;

    int col_5 = 5;
    // test case 5
    cout << "Expected: 0, Actual: " << col_has_no_threes_of_color(board, size_2, col_5, BLUE) << endl;

}

void test_board_has_no_threes() {
    int board[MAX_SIZE][MAX_SIZE];

    cout << "\nNow testing: board_has_no_threes()" << endl;

    string test_board_1[] = { "X--X",
                             "OXOX",
                             "X-OO",
                             "OO-O" };
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    // test case 1 
    cout << "Expected: 1, Actual: " << board_has_no_threes(board, size_1) << endl;

    string test_board_2[] = { "XO-X",
                             "OX--",
                             "XX-O",
                             "OO-O" };
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    // test case 2 
    cout << "Expected: 1, Actual: " << board_has_no_threes(board, size_2) << endl;
    
    string test_board_3[] = {"XOXX",
                             "OXX-",
                             "XOXO",
                             "O--O" };
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    // test case 3 
    cout << "Expected: 0, Actual: " << board_has_no_threes(board, size_3) << endl;

    string test_board_4[] = {"XXOX--",
                             "O-X-OO",
                             "XX-XX-",
                             "OXO--O",
                             "-OOXXX",
                             "--X-X-" };
    int size_4 = 6;
    read_board_from_string(board, test_board_4, size_4);
    // test case 4 
    cout << "Expected: 0, Actual: " << board_has_no_threes(board, size_4) << endl;

    string test_board_5[] = { "XXOX--",
                             "O-X-OO",
                             "XXOXX-",
                             "OXO--O",
                             "-OOX-X",
                             "--X-X-" };
    int size_5 = 6;
    read_board_from_string(board, test_board_5, size_5);
    // test case 5
    cout << "Expected: 0, Actual: " << board_has_no_threes(board, size_5) << endl;
}

void test_solve_balance_row() {
    int board[MAX_SIZE][MAX_SIZE];

    cout << "\nNow testing: solve_balance_row()" << endl;
    string test_board_1[] = { "-O-O",
                             "XX--",
                             "XX-O",
                             "OO-O" };
    int size_1 = 4;
    int row_1 = 1;
    read_board_from_string(board, test_board_1, size_1);
    // test case 1 
    cout << "Expected: marking (2, C) and (2, D) as O  Actual: ";
    solve_balance_row(board, size_1, row_1, true);
    cout << endl << endl;

    int row_2 = 0;
    // test case 2 
    cout << "Expected: marking (1, A) and (1, C) as X  Actual: ";
    solve_balance_row(board, size_1, row_2, true);
    cout << endl << endl;

    string test_board_2[] = { "-O-O-X",
                             "XX--XO",
                             "XX-O-O",
                             "OO-OXX",
                             "OX-O-O",
                             "OX--OX" };
    int size_2 = 6;
    int row_3 = 1;
    read_board_from_string(board, test_board_2, size_2);
    // test case 3
    cout << "Expected: marking (2, C) and (2, D) as O  Actual: ";
    solve_balance_row(board, size_2, row_3, true);
    cout << endl << endl;
    
    int row_4 = 3;
    // test case 4
    cout << "Expected:  marking (4, C) as X  Actual: ";
    solve_balance_row(board, size_2, row_4, true);
    cout << endl << endl;

    int row_5 = 4;
    // test case 5
    cout << "Expected: marking (5, C) and (5, E) as X  Actual: ";
    solve_balance_row(board, size_2, row_5, true);
    cout << endl << endl;
}

void test_solve_balance_column() {
    int board[MAX_SIZE][MAX_SIZE];

    cout << "\nNow testing: solve_balance_column()" << endl;
    string test_board_1[] = {"-O-O",
                             "X-X-",
                             "X--O",
                             "-O-O" };
    int size_1 = 4;
    int col_1 = 1;
    read_board_from_string(board, test_board_1, size_1);
    // test case 1 
    cout << "Expected: marking (2, B) and (3, B) as X  Actual: ";
    solve_balance_column(board, size_1, col_1, false);
    cout << endl << endl;

    int col_2 = 0;
    // test case 2 
    cout << "Expected: marking (1, A) and (4, A) as X  Actual: ";
    solve_balance_column(board, size_1, col_2, false);
    cout << endl << endl;

    string test_board_2[] = {"-O-O-X",
                             "XX--XO",
                             "XX-O-O",
                             "O--OOX",
                             "OX-XOO",
                             "O---OX" };
    int size_2 = 6;
    int col_3 = 1;
    read_board_from_string(board, test_board_2, size_2);
    // test case 3
    cout << "Expected: marking (4, B) and (6, B) as O  Actual: ";
    solve_balance_column(board, size_2, col_3, false);
    cout << endl << endl;

    int col_4 = 3;
    // test case 4
    cout << "Expected: marking (2, D) and (6, D) as X  Actual: ";
    solve_balance_column(board, size_2, col_4, false);
    cout << endl << endl;

    int col_5 = 4;
    // test case 5
    cout << "Expected: marking (1, E) and (3, E) as X  Actual: ";
    solve_balance_column(board, size_2, col_5, false);
    cout << endl << endl;

}

void test_rows_are_different() {
    int board[MAX_SIZE][MAX_SIZE];

    cout << "\nNow testing: rows_are_different()" << endl;

    string test_board_1[] = { "XXXX",
                             "----",
                             "XXXX",
                             "----" };
    int size_1 = 4;
    int row_1 = 0;
    int row_2 = 2;
    read_board_from_string(board, test_board_1, size_1);
    // test case 1 
    cout << "Expected: 0, Actual: " << rows_are_different(board, size_1, row_1, row_2) << endl;

    int row_3 = 1;
    int row_4 = 3;
    // test case 2 
    cout << "Expected: 1, Actual: " << rows_are_different(board, size_1, row_3, row_4) << endl;

    string test_board_2[] = {"XXXX--",
                             "XXOOXO",
                             "XXXX--",
                             "OOOOOO",
                             "XOOXXO",
                             "OOOOOO" };
    int size_2 = 6;
    int row_5 = 0;
    int row_6 = 2;
    read_board_from_string(board, test_board_2, size_2);
    // test case 3
    cout << "Expected: 1, Actual: " << rows_are_different(board, size_2, row_5, row_6) << endl;

    int row_7 = 3;
    int row_8 = 5;
    // test case 4 
    cout << "Expected: 0, Actual: " << rows_are_different(board, size_2, row_7, row_8) << endl;

    int row_9 = 3;
    int row_10 = 4;
    // test case 5
    cout << "Expected: 1, Actual: " << rows_are_different(board, size_2, row_9, row_10) << endl;
}

void test_cols_are_different() {
    int board[MAX_SIZE][MAX_SIZE];

    cout << "\nNow testing: cols_are_different()" << endl;

    string test_board_1[] = {"XOOX",
                             "-OO-",
                             "XXXX",
                             "-XX-" };
    int size_1 = 4;
    int col_1 = 1;
    int col_2 = 2;
    read_board_from_string(board, test_board_1, size_1);
    // test case 1 
    cout << "Expected: 0, Actual: " << cols_are_different(board, size_1, col_1, col_2) << endl;

    int col_3 = 0;
    int col_4 = 4;
    // test case 2 
    cout << "Expected: 1, Actual: " << cols_are_different(board, size_1, col_3, col_4) << endl;

    string test_board_2[] = {"XX-X--",
                             "XXXOXO",
                             "XX-X--",
                             "OOOOOO",
                             "XXXXXO",
                             "OOOOOO" };
    int size_2 = 6;
    int col_5 = 0;
    int col_6 = 1;
    read_board_from_string(board, test_board_2, size_2);
    // test case 3
    cout << "Expected: 0, Actual: " << cols_are_different(board, size_2, col_5, col_6) << endl;

    int col_7 = 2;
    int col_8 = 4;
    // test case 4 
    cout << "Expected: 1, Actual: " << cols_are_different(board, size_2, col_7, col_8) << endl;

    int col_9 = 3;
    int col_10 = 5;
    // test case 5
    cout << "Expected: 1, Actual: " << cols_are_different(board, size_2, col_9, col_10) << endl;
}

void test_board_has_no_duplicates() {
    int board[MAX_SIZE][MAX_SIZE];

    cout << "\nNow testing: board_has_no_duplicates()" << endl;

    string test_board_1[] = {"XXOO",
                             "OXOX",
                             "XXXX",
                             "OOOO" };
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    // test case 1 
    cout << "Expected: 1, Actual: " << board_has_no_duplicates(board, size_1) << endl;

    string test_board_2[] = {"XXXO",
                             "OXOX",
                             "XXXO",
                             "OOOO" };
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    // test case 2
    cout << "Expected: 0, Actual: " << board_has_no_duplicates(board, size_2) << endl;

    string test_board_3[] = {"XOXX",
                             "XXXO",
                             "OOOX",
                             "OXOO" };
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    // test case 3
    cout << "Expected: 0, Actual: " << board_has_no_duplicates(board, size_3) << endl;

    string test_board_4[] = { "XOXOOX",
                             "XOXXOO",
                             "OXOXXX",
                             "OXXOXX",
                             "XOOXXO",
                             "OOXOXO" };
    int size_4 = 6;
    read_board_from_string(board, test_board_4, size_4);
    // test case 4
    cout << "Expected: 1, Actual: " << board_has_no_duplicates(board, size_4) << endl;

    string test_board_5[] = { "XOXOOX",
                             "OXOXXO",
                             "XXOXXO",
                             "OXOXOO",
                             "XOOXOX",
                             "OXXXOO" };
    int size_5 = 6;
    read_board_from_string(board, test_board_5, size_5);
    // test case 5
    cout << "Expected: 1, Actual: " << board_has_no_duplicates(board, size_5) << endl;
}

void test_solve_three_in_a_row() {
    int board[MAX_SIZE][MAX_SIZE];

    cout << "\nNow testing: solve_three_in_a_row()" << endl;

    string test_board_1[] = { "O-OO",
                             "X-XO",
                             "OO--",
                             "-OO-" };
    int size_1 = 4;
    int row_1 = 0;
    read_board_from_string(board, test_board_1, size_1);
    // test case 1 
    cout << "Expected: marking (1, B) as X , Actual: ";
    solve_three_in_a_row(board, size_1, row_1, true);

    int row_2 = 1;
    // test case 2
    cout << "\n\nExpected: marking (2, B) as O, Actual: ";
    solve_three_in_a_row(board, size_1, row_2, true);

    int row_3 = 3;
    // test case 3
    cout << "\n\nExpected: marking (4, A) and (4, D) as X , Actual: ";
    solve_three_in_a_row(board, size_1, row_3, true);

    string test_board_2[] = { "--O-XX",
                             "OO---X",
                             "OXO-OX",
                             "OX--OO",
                             "X-X-XX",
                             "OOXOXO" };
    int size_2 = 6;
    read_board_from_string(board, test_board_2, size_2);
    int row_4 = 4;
    // test case 4
    cout << "\n\nExpected: marking (5, B) and (5, D) as O , Actual: ";
    solve_three_in_a_row(board, size_2, row_4, true);

    int row_5 = 0;
    // test case 5
    cout << "\n\nExpected: marking (1, D) as O , Actual: ";
    solve_three_in_a_row(board, size_2, row_5, true);
    cout << endl;
}

void test_solve_three_in_a_column() {
    int board[MAX_SIZE][MAX_SIZE];

    cout << "\nNow testing: solve_three_in_a_column()" << endl;

    string test_board_1[] = { "OO--",
                             "OX-O",
                             "--OO",
                             "OXO-" };
    int size_1 = 4;
    int col_1 = 0;
    read_board_from_string(board, test_board_1, size_1);
    // test case 1 
    cout << "Expected: marking (3, A) as X , Actual: ";
    solve_three_in_a_column(board, size_1, col_1, true);

    int col_2 = 1;
    // test case 2
    cout << "\n\nExpected: marking (3, B) as O , Actual: ";
    solve_three_in_a_column(board, size_1, col_2, true);

    int col_3 = 3;
    // test case 3
    cout << "\n\nExpected: marking (1, D) and (4, D) as X , Actual: ";
    solve_three_in_a_column(board, size_1, col_3, true);

    string test_board_2[] = {"XXXOXO",
                             "X-OOXX",
                             "-----O",
                             "O-O-XX",
                             "-OXX-O",
                             "-OOOXO" };
    int size_2 = 6;
    read_board_from_string(board, test_board_2, size_2);
    int col_4 = 4;
    // test case 4
    cout << "\n\nExpected: marking (3, E) and (5, E) as O , Actual: ";
    solve_three_in_a_column(board, size_2, col_4, true);

    int col_5 = 0;
    // test case 5
    cout << "\n\nExpected: marking (3, A) and (5, A) as O , Actual: ";
    solve_three_in_a_column(board, size_2, col_5, true);
}

void test_board_is_solved() {
    int board[MAX_SIZE][MAX_SIZE];

    cout << "\nNow testing: board_is_solved()" << endl;

    string test_board_1[] = { "OXXO",
                             "XOXO",
                             "OXOX",
                             "XOOX" };
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    // test case 1 
    cout << "Expected: 1, Actual: " << board_is_solved(board, size_1) << endl;

    string test_board_2[] = { "OXXO",
                             "XOXO",
                             "O-OX",
                             "XOOX" };
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    // test case 2 
    cout << "Expected: 0, Actual: " << board_is_solved(board, size_2) << endl;

    string test_board_3[] = { "XXOOXXOO",
                             "OOXXOXXO",
                             "OXOOXOXX",
                             "XOOXXOOX",
                             "XOXOOXXO",
                             "OXXOOXOX",
                             "OXOXXOOX",
                             "XOXXOOXO"};
    int size_3 = 8;
    read_board_from_string(board, test_board_3, size_3);
    // test case 3 
    cout << "Expected: 1, Actual: " << board_is_solved(board, size_3) << endl;

    string test_board_4[] = { "XOXXXO",
                             "XOXOOX",
                             "OXOX--",
                             "XOOXOX",
                             "XO-OX-",
                             "XO--OX"};
    int size_4 = 6;
    read_board_from_string(board, test_board_4, size_4);
    // test case 4
    cout << "Expected: 0, Actual: " << board_is_solved(board, size_4) << endl;

    string test_board_5[] = { "XO--XO",
                             "X-X-XX",
                             "OXOX--",
                             "X--XOX",
                             "XO-OX-",
                             "XO--OX" };
    int size_5 = 6;
    read_board_from_string(board, test_board_5, size_5);
    // test case 5
    cout << "Expected: 0, Actual: " << board_is_solved(board, size_5) << endl;
}

void test_check_valid_input() {

    cout << "\nNow testing: check_valid_input()" << endl;

    int size_1 = 6;
    int row_1 = 1;
    char col_1 = 'b';
    char color_1 = 'x';
    int row = 2;
    int col = 3;

    // test case 1
    cout << "\nExpected: 1  row = 0  col = 1, \tActual: ";
    cout << check_valid_input(size_1, row_1, col_1, color_1, row, col);
    cout << "  row = " << row << " col = " << col << endl;


    int row_2 = 6;
    char col_2 = 'a';
    char color_2 = '-';

    // test case 2
    cout << "\nExpected: 1  row = 5  col = 0, \tActual: ";
    cout << check_valid_input(size_1, row_2, col_2, color_2, row, col);
    cout << "  row = " << row << " col = " << col << endl;

    int row_3 = 7;
    char col_3 = 'c';
    char color_3 = 'O';

    // test case 3
    cout << "\nExpected: 0 \tActual: ";
    cout << check_valid_input(size_1, row_3, col_3, color_3, row, col);

    int row_4 = 2;
    char col_4 = 'h';
    char color_4 = 'X';

    // test case 4
    cout << "\nExpected: 0 \tActual: ";
    cout << check_valid_input(size_1, row_4, col_4, color_4, row, col);

    int row_5 = 5;
    char col_5 = 'd';
    char color_5 = 'r';

    // test case 5
    cout << "\nExpected: 0 \tActual: ";
    cout << check_valid_input(size_1, row_5, col_5, color_5, row, col);
}

void test_check_valid_move() {

    int board[MAX_SIZE][MAX_SIZE];
    int board2[MAX_SIZE][MAX_SIZE];

    cout << "\n\nNow testing: check_valid_move()" << endl;

    string test_board_1[] = { "X--O",
                             "X--O",
                             "OX-X",
                             "--OX" };

    string test_board_2[] = {"XXOO",
                             "X--O",
                             "OX-X",
                             "OOOX" };
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    read_board_from_string(board2, test_board_2, size_1);

    int row_1 = 1;
    int col_1 = 1;
    // test case 1 
    cout << "Expected: 0, Actual: " << check_valid_move(board, board2, size_1, row_1, col_1, 1) << endl;

    int row_2 = 2;
    int col_2 = 2;
    // test case 2
    cout << "Expected: 0, Actual: " << check_valid_move(board, board2, size_1, row_2, col_2, 2) << endl;

    int row_3 = 0;
    int col_3 = 3;
    // test case 3
    cout << "Expected: 0, Actual: " << check_valid_move(board, board2, size_1, row_3, col_3, 1) << endl;

    string test_board_3[] = {"X--O",
                             "X--O",
                             "O--X",
                             "O--X" };

    string test_board_4[] = {"X-OO",
                             "X--O",
                             "OX-X",
                             "O-OX" };
    int size_2 = 4;
    read_board_from_string(board, test_board_3, size_2);
    read_board_from_string(board2, test_board_4, size_2);

    int row_4 = 3;
    int col_4 = 1;
    // test case 4
    cout << "Expected: 1, Actual: " << check_valid_move(board, board2, size_2, row_4, col_4, 1) << endl;


    int row_5 = 1;
    int col_5 = 1;
    // test case 5 
    cout << "Expected: 1, Actual: " << check_valid_move(board, board2, size_2, row_5, col_5, 2) << endl;
}