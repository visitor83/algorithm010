/*
 * @lc app=leetcode.cn id=547 lang=c
 *
 * [547] 朋友圈
 */

// @lc code=start

// 并查集
int Ufind(int x, int *parent)
{
    if (x != parent[x]) {
        parent[x] = Ufind(parent[x], parent);
    }
    return parent[x];
}

bool IsConnected(int a, int b, int *parent)
{
    return Ufind(a, parent) == Ufind(b, parent) ? true : false;
}

void MakeSet(int a , int b, int *parent)
{
    int rootA = Ufind(a, parent), rootB = Ufind(b, parent);

    if (rootA != rootB) {
        parent[rootA] = rootB;
    }
}

int findCircleNum(int** M, int MSize, int* MColSize)
{
    // 初始化并查集
    int mCnt, i, j;
    int *parent;
    
    if (MSize <= 1) {
        return 1;
    }

    mCnt = MSize;
    parent = calloc(mCnt + 1, sizeof(int));
    for (i = 0; i < mCnt; i++) {
        parent[i] = i;
    }

    for (i = 0; i < MSize; i++) {
        for (j = 0; j < MColSize[0]; j++) {
            if (M[i][j] && !IsConnected(i, j, parent)) {
                MakeSet(i, j,parent);
                mCnt--;
            }
        }
    }
    return mCnt;
}
/* 方法二： DFS求联通分量 */

#define N 210
bool *g_vis = NULL;
void dfs(int **M, int row, const int col)
{
    g_vis[row] = true;
    for (int j = 0; j < col; j++) {
        if (M[row][j] && !g_vis[j]) {
            dfs(M, j, col);
        } 
    }
}

int findCircleNum2(int** M, int MSize, int* MColSize)
{
    int friends ;
    if (MSize <= 1) {
        return 1;
    }
    g_vis = calloc(N, sizeof(bool));
    friends = 0;
    for (int i = 0; i < MSize; i++) {
        if (!g_vis[i]) {        
            dfs (M, i, MColSize[i]);
            friends++;
        }
    }
    free(g_vis);
    return friends;
}


// @lc code=end

