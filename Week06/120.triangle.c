/*
 * @lc app=leetcode.cn id=120 lang=c
 *
 * [120] 三角形最小路径和
 */

// @lc code=start

// Recursive
int GetTrian(int **triangle, int row, int i, int j)
{
    //printf("(%d, %d)\n", i, j);
    if (i + 1 >= row) {
        return triangle[i][j];
    }
    return triangle[i][j] + 
    fmin(GetTrian(triangle, row, i+1, j) , 
         GetTrian(triangle, row, i+1, j+1));
}

int minimumTotal2(int** triangle, int triangleSize, int* triangleColSize)
{
    return GetTrian(triangle, triangleSize, 0, 0);
}


// DP
int minimumTotal(int** triangle, int triangleSize, int* triangleColSize)
{
    int i, j;
    int **dp;
    
    dp = calloc(triangleSize + 1, sizeof(int*));
    for (i = 0; i <= triangleSize; i++) {
        dp[i] = calloc(triangleColSize[triangleSize - 1] + 1, sizeof(int));
    }

    for (i = 0; i < triangleColSize[triangleSize - 1]; i++){
        dp[triangleSize - 1][i] = triangle[triangleSize - 1][i];
    }

    //printf("%d\n", dp[3][0]);
    for (i = triangleSize - 2; i != -1; --i){
        for (j = triangleColSize[i] - 1; j != -1; --j){
            dp[i][j] = fmin(dp[i+1][j], dp[i+1][j+1]) + triangle[i][j];
        } 
    }

    return dp[0][0];
}

// @lc code=end

