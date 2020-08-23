/*
在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？

 

示例 1:

输入: 
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 12
解释: 路径 1→3→5→2→1 可以拿到最多价值的礼物

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

int myfunc(int **grid, int x, int y,  int **dp ) {
    if (x == 0 && y == 0) {
        return dp[x][y] = grid[x][y];
    }

    if (dp[x][y] !=0) {
        return dp[x][y];
    }

    if (x == 0 && y > 0)  {
        return  dp[x][y] = myfunc(grid, x, y - 1, dp) + grid[x][y];
    }
    if (y == 0 && x >0) {
        return dp[x][y] = myfunc(grid, x -1 , y , dp) + grid[x][y];
    }

    return dp[x][y] = fmax(myfunc(grid, x, y - 1, dp ), myfunc(grid, x-1, y, dp )) + grid[x][y];
}
int maxValue2(int** grid, int gridSize, int* gridColSize){
    int **dp, i;

    dp = calloc(gridSize, sizeof(int*));
    for (i = 0; i < gridSize; i++) {
        dp[i] = calloc(gridColSize[0], sizeof(int));
    }
    return myfunc(grid, gridSize - 1, gridColSize[0] - 1,dp );
   // return dp[gridSize-1][gridColSize[0]-1];
}
// 最优子结构: 问题的最优解包含子问题的最优解
int maxValue(int** grid, int gridSize, int* gridColSize){
    int **dp, i, j;

    dp = calloc(gridSize + 1, sizeof(int*));
    for (i = 0; i < gridSize; i++) {
        dp[i] = calloc(gridColSize[0] + 1, sizeof(int));
    }

    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < gridColSize[i]; j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = grid[i][j];
            } else if (i == 0 && j > 0) {
                dp[i][j] = dp[i][j-1] + grid[i][j];
            } else if (j == 0 && i > 0) {
                dp[i][j] = dp[i-1][j] + grid[i][j];
            } else {
                dp[i][j] = fmax(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }  
        }
    }
    return dp[gridSize-1][gridColSize[0]-1];
}