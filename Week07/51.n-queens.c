/*
 * @lc app=leetcode.cn id=51 lang=c
 *
 * [51] N皇后
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char *** solveNQueens(int n, int* returnSize, int** returnColumnSizes){

}


bool Validate2(int *vis, int R, int C) {
    for (int i = 0; i < R; i++) {
        if (C == vis[i] || R + C == (vis[i] + i) || R -C == i - vis[i])
            return false;
    }
    return true;
}
bool Validate(int n, int *vis, int row, int col) {
    int i, j;
    for (i = 0; i < row; i++) {
        if (vis[i] == col) {
            return false;
        }
    }
    for (i = row - 1, j = col + 1; j < n && i >= 0; i--, j++) {
        if (vis[i] == j) {
            return false;
        }
    }
    for (i = row -1, j = col - 1; j >=0 && i >= 0; i--, j--) {
        if (vis[i] == j) {
            return false;
        }
    }
    return true;
}
void backtrack(int n, int row, char ***ans, int *vis, int *returnSize) {
    // terminator
    if (row == n) {
        ans[*returnSize] = calloc(n, sizeof(char*));
        for (int i = 0; i < n; i++) {
            ans[*returnSize][i] = calloc(n+1, sizeof (char));
            memset(ans[*returnSize][i], '.', n);
            ans[*returnSize][i][vis[i]] ='Q';
        }
        (*returnSize)++;
        return ;
    }
    // current logic
    for (int col = 0; col < n; col++) {
        if (Validate(n, vis, row, col)) {
            // drill down
            vis[row] = col;
            backtrack(n, row+1, ans, vis,  returnSize);
            // revert state
            vis[row] = -1;
        }
    }
}
char *** solveNQueens(int n, int* returnSize, int** returnColumnSizes){
    char ***ans;
    int *vis;

    *returnSize = 0;
    ans = calloc(n*n*n, sizeof(char**));
    vis = calloc(n + 1, sizeof(int));

    backtrack(n, 0, ans, vis, returnSize);
    *returnColumnSizes = calloc(*returnSize, sizeof(int));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = n;
    }
    return ans;
}

// @lc code=end

