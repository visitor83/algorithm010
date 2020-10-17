/*
 * @lc app=leetcode.cn id=52 lang=c
 *
 * [52] N皇后 II
 */

// @lc code=start
int g_ans;
bool Check(int n, int *cols, int x, int y) {
    int i, j;
    for (i = 0; i < x; i++) {
        if (cols[i] == y) { return false; }
    }

    for (i = x - 1, j = y + 1; j < n && i >= 0; i--, j++) {
        if (cols[i] == j) {
            return false;
        }
    }
    for (i = x -1, j = y - 1; j >=0 && i >= 0; i--, j--) {
        if (cols[i] == j) {
            return false;
        }
    }

    return true;
}

bool myfunc(int n, int x, int y, int *cols) {
    if (x == n) {
        printf("end\n");
        g_ans++;
        return true;
    }
    int j;
    for (j = 0; j < n; j++) {
        if (Check(n, cols, x, j)) {
            cols[x] = j; 
            myfunc(n, x + 1, j, cols);
            cols[x] = -1;
        }
    }
    return true;
}

int totalNQueens(int n){
    int *cols = calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        cols[i] = -1;
    }
    g_ans = 0;
    myfunc(n, 0, 0, cols);
    return g_ans;
}


// @lc code=end

