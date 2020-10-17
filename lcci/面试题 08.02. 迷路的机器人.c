/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
typedef struct tagMap {
    int pos;
    UT_hash_handle hh;
} Map;
Map  *g_mapPtr;
bool myfunc(int **grid, int ROW, int COL, int x, int y, int * returnSize, bool *found, 
    int **ans) {
    bool res = false;
    int pos;
    Map *el = NULL;
    if (x < 0 || y < 0 || grid[x][y] == 1) {
        return false;
    }
    if (*found) { return true; }
    pos = x << 8 | y;
    HASH_FIND_INT(g_mapPtr, &pos, el);
    if (el) {
        return false;
    }
    res = (x == 0 && y == 0 ) || myfunc(grid, ROW, COL, x, y -1, returnSize, found, ans) ||
        myfunc(grid, ROW, COL, x-1, y , returnSize, found,ans);
    if (res) {
        ans[*returnSize] = calloc(2, sizeof(int));
        ans[*returnSize][0] = x; ans[*returnSize][1] = y;
        (*returnSize)++;
        //printf(" (%d, %d), ", x, y);
        if (x == 0 && y == 0) { *found = true; }
        return true;
    }
    el = calloc(1, sizeof(Map)); el->pos = x << 8 | y ;
    HASH_ADD_INT(g_mapPtr, pos, el);
    return false;
}
#define N 10010
int** pathWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize, int* returnSize, int** returnColumnSizes){
    int R, C, x, y;
    int **ans;
    bool found = false;

    g_mapPtr = NULL;
    ans = calloc(N, sizeof(int*));

    *returnSize = 0;
    R = obstacleGridSize; C = obstacleGridColSize[0];
    x = R - 1; y = C - 1;
    myfunc(obstacleGrid, R, C, x, y, returnSize, &found, ans);
    if (!found) {
        return ans;
    }
    //printf(" \nreturnSize %d\n", *returnSize);
    *returnColumnSizes = calloc(*returnSize + 1, sizeof(int)); 
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = 2;
    }
    return ans;
}