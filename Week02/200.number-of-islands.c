/*
 * @lc app=leetcode.cn id=200 lang=c
 *
 * [200] 岛屿数量
 */

// @lc code=start

/*
 * @lc app=leetcode.cn id=200 lang=c
 *
 * [200] 岛屿数量
 */

// @lc code=start

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define VISITED  2

char **g_seen;

void Init(int row, int col)
{
    g_seen = calloc(row, sizeof(char *));
    for (int i = 0; i < row; i++) {
        g_seen[i] = calloc(col, sizeof(char));
    }
}

bool IsValid(int row, int col, int nextX, int nextY)
{
    if (nextX < 0 || nextY < 0 || nextX >= row || nextY >= col) {
        return false;
    }
    return true;
}

void dfs(char **grid, int startX, int startY, int row, int col)
{
    const int dirSize = 4;
    int i;
    int nextX, nextY;
    int dx[] = { 1, -1, 0, 0 };
    int dy[] = { 0,  0, 1, -1};

    g_seen[startX][startY] = VISITED;

    for (i = 0; i < dirSize; i++) {
        nextX = startX + dx[i];
        nextY = startY + dy[i];
        if (IsValid(row, col, nextX, nextY) && 
                !g_seen[nextX][nextY] && (grid[nextX][nextY] == '1')) {
            dfs(grid, nextX, nextY, row, col);
        }
    }
}

int numIslands(char** grid, int gridSize, int* gridColSize)
{
    int i, j;
    int ans;

    if (!grid || gridSize <= 0) {
        return 0;
    }

    ans = 0;
    Init(gridSize, gridColSize[0]);

    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < gridColSize[i]; j++) {
           if (grid[i][j] == '1' && (g_seen[i][j] != VISITED)) {
               //printf("start (%d, %d)\n", i, j);
               dfs(grid, i, j, gridSize, gridColSize[i]);
               ans++;
           }
        }
    }

    for (i = 0;  i < gridSize ; i++) {
        free(g_seen[i]);
    }
    free(g_seen);
    return ans;
}


// @lc code=end
// @lc code=end

