/*
 * @lc app=leetcode.cn id=37 lang=c
 *
 * [37] 解数独
 */

// @lc code=start

#include <stdbool.h>
int N;
bool Validate(char ** board, char **a, int x, int y, char val, 
    int N)
{
    int i, j;
    // row
    for (i = 0; i < N; i++) {
        if (a[x][i] == val )  {
            return false;
        }
    }
    // col
    for (i = 0; i < N; i++) {
        if (a[i][y] == val )  {
            return false;
        }
    }
    int x0, y0;
    x0 = (x / 3 ) * 3; y0 = (y / 3) *3;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (a[x0 + i][y0+j] == val) {
                return false;
            }
        }
    }
    return true;
}

bool Backtrace(char **board, char **a, int x, int y, int N) 
{
    if (x == 9 ) {
        return true;
    }

    if (y == 9) {
       //x = x + 1;  y = 0;
       return Backtrace(board, a, x+1, 0, N);
    }     

/*
    if (x < 0 || y < 0 || x >= N || y >= N) {
        return false;
    }
    */

    if (board[x][y] != '.') {
        // move to next
        return Backtrace(board, a, x, y + 1, N);
    }

    for (int i = 0; i < 9; i++) {
      if (Validate(board, a, x, y, i + '1', N)) {
          a[x][y] = i+'1';
          if (Backtrace(board, a, x, y + 1, N)) {
              return true;
          }
          a[x][y] = '.';
      }
    }
    return false;
}

void solveSudoku(char** board, int boardSize, int* boardColSize){
    int i, j;
    char **a;
    N = boardSize;
    a = calloc(N, sizeof(char*));
    for (int i = 0; i < N; i++) {
        a[i] = calloc(N, sizeof(char));
        memcpy(a[i], board[i], N);
    }
    
    Backtrace(board, a, 0, 0, N);

    for (int i = 0; i < N; i++) {
        memcpy(board[i], a[i], N);
        free(a[i]);
    }
}

// @lc code=end

