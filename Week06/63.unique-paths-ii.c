/*
 * @lc app=leetcode.cn id=63 lang=c
 *
 * [63] 不同路径 II
 */

// @lc code=start

int uniquePathsWithObstacles(int** ob, int row, int* col)
{
    int **dp;
    int i, j;

    dp = calloc(row, sizeof(int *));
    for (int i = 0; i < row; i++) {
        dp[i] = calloc(col[0], sizeof(int));
    }

    dp[0][0] = ob[0][0] == 1 ? 0 : 1;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col[i]; j++) {
            if (ob[i][j]) {
                dp[i][j] = 0;
            } else if (i == 0 ){
                if (j > 0) {
                    dp[i][j] = dp[i][j-1];
                }
            } else if (j == 0 ) {
                if (i > 0 ) {
                    dp[i][j] = dp[i-1][j];
                }
            }
            else {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];

            }
        }
    }
    return dp[row-1][col[0]-1];
}


int GetUniqPath(int **ob, int x, int y, int **dp)
{
    if (x < 0 || y < 0 || ob[x][y]) {
        return 0;
    }

    if (x == 0 && y == 0) {
        return 1;
    }

    if (dp[x][y]) {
        return dp[x][y];
    }
    return dp[x][y] = GetUniqPath(ob, x - 1, y, dp) + GetUniqPath(ob, x, y - 1, dp);
}

int uniquePathsWithObstacles2(int** obstacleGrid, int obstacleGridSize, 
    int* obstacleGridColSize)
{
    int **dp;

    dp = calloc(obstacleGridSize, sizeof(int *));
    for (int i = 0; i < obstacleGridSize; i++) {
        dp[i] = calloc(obstacleGridColSize[i], sizeof(int));
    }
    return GetUniqPath(obstacleGrid, obstacleGridSize - 1, 
            obstacleGridColSize[0] - 1, dp);
}
// @lc code=end

