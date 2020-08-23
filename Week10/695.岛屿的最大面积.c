/*
 * @lc app=leetcode.cn id=695 lang=c
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
int gR, gC;
int dfs(int **arr, int x, int y, int *areaSize) {
    int dx[] = {1, -1, 0, 0   };
    int dy[] = {0,  0, 1, -1  };
    if (x < 0 || y < 0 || x >= gR || y >= gC) {
        return 0;
    }
    if (!arr[x][y]) {
        return 0;
    } 

    arr[x][y] = 0;
    ++(*areaSize);
    for (int j = 0;  j < 4; j++) {
        dfs(arr, x + dx[j], y + dy[j], areaSize);
    }
    return 0;
}
int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    int i, j, ans;
    // 有多少个1
    if (!grid) {
        return 0;
    }
    ans = 0;
    gR = gridSize; gC = gridColSize[0];
    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < gridColSize[0]; j++) {
            if (grid[i][j]) {
                int areaSize = 0;
                dfs(grid, i, j, &areaSize);
                ans = fmax(ans, areaSize);
            }
        }
    }
    return ans;
}

// @lc code=end

