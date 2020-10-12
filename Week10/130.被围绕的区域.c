/*
 * @lc app=leetcode.cn id=130 lang=c
 *
 * [130] 被围绕的区域
 */

// @lc code=start

// DFS: 找到边界的'O'，求与之连通量 'D'
// BFS: 从边界的'X', 开始同步向里边走， 碰到'O'就'X'
// 并查集： 把边界的所有'O'找到，求所有与之并的集合，剩下的就是结果

bool *g_visited;
void dfs(char **board, int i, int j, const int R, const int C) {
    if (i < 0 || j < 0 || i >= R || j >= C) {
        return ;
    }
    if (g_visited[i * C + j] || board[i][j] != 'O') {
        return ;
    }
    int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
    g_visited[i * C + j] = true;
    board[i][j] = '#';
    for (int k = 0; k < 4; k++) {
        dfs(board, i + dx[k], j + dy[k], R, C);
    }
}

void solve(char** board, int boardSize, int* boardColSize) {
    if (!board || boardSize <= 0 ) { 
        return ;
    }
    const int R = boardSize, C = boardColSize[0];
    int i, j;
    g_visited = calloc(R *C + 1, sizeof(bool));
    for (i = 0;  i < R; i++) {
        for (j = 0; j < C; j++) {
            bool isEdge = (j == 0 || i == 0 || j == C -1 || i == R -1);
            if (isEdge && (board[i][j] == 'O')) {
                dfs(board, i, j, R, C);
            }
        }
    }

    for (i = 0; i < R; i++) {
        for (j = 0; j < C; j++) {
            if (board[i][j] == '#') {
                board[i][j] = 'O';
            } else if (board[i][j] == 'O') {
                board[i][j] = 'X';
            }
        }
    } 
}
// @lc code=end

