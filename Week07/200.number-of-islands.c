/*
 * @lc app=leetcode.cn id=200 lang=c
 *
 * [200] 岛屿数量
 */

// @lc code=start

int *g_parent;
int g_islandNum;

// 并查集
int UF_Find(int i) {
    if (i != g_parent[i]) {
        g_parent[i] = UF_Find(g_parent[i]);
    }
    return g_parent[i];
}

void UF_Union(int x, int y, int nx, int ny, const int R, const int C) {
    int rootA = UF_Find(x * C + y);
    int rootB = UF_Find(nx * C + ny);

    if (rootA != rootB) {
        g_parent[rootA] = rootB;
        --g_islandNum;
    }
}

void UF_MakeSet(char **grid, int x, int y, const int R, const int C) {
    int dx[] = { -1, 1, 0, 0 }, dy[] = {0, 0, -1, 1};
    for (int i = 0; i < 4; i++) {
        int nx, ny;

        nx = x+dx[i]; ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= R || ny >= C) {
            continue;
        }
        if (grid[nx][ny] == '0') {
            continue;
        }

        //printf("(  %d, %d)  -- (%d, %d)\n", x, y, nx, ny);
        UF_Union(x, y, nx, ny, R, C);
    }
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    // 初始化并查集数据
    int i, j;
    const int R = gridSize, C = gridColSize[0];

    if (!grid || gridSize <= 0) {
        return 0;
    }
    g_parent = calloc(R * C, sizeof(int));
    g_islandNum = 0;
    for (i = 0; i < R; i++) {
        for (j = 0; j < C; j++) {
            if (grid[i][j] == '1') {
                g_parent[i * C + j] =  i * C + j;
                g_islandNum++;
            }
        }
    }
    // 判断1的点， 是否parent[i] == i如果是，判断水平或竖直方向合并
    for (i =  0; i < R; i++) {
        for (j = 0; j < C; j++) {
            if ((grid[i][j] == '1')) {
                //grid[i][j] = '0';
                if (g_parent[(i * C) + j] == (i * C) + j) {
                   UF_MakeSet(grid, i, j, R, C);
                }
            }
        }
    }
    return g_islandNum;
}

// DFS 
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

