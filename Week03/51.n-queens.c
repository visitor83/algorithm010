/*
 * @lc app=leetcode.cn id=51 lang=c
 *
 * [51] N皇后
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define VISITED 2

/* temporily save one of the result */
typedef struct tagNode {
    char **g;
    struct tagNode *next;
} Node;

int *g_col;
int g_ansCnt;
Node g_head, *g_tail;

void SaveResult(int n, int len)
{
    int i, j;
    char ** graph;
        
    graph = calloc(n, sizeof(char*));
    for (i = 0; i < n; i++) {
        graph[i] = calloc(n, sizeof(char));
        memset(graph[i], '.', sizeof(char) *n);
    }

    for (i = 0; i < n; i++) {
        graph[i][g_col[i]] = 'Q';
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%c", graph[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    Node *node = calloc(1, sizeof(Node));
    node->g = graph;
    g_tail->next = node; 
    g_tail = node;
}
bool check(int row, int col) {
  for (int i = 0; i < row; i++)
    if (col == g_col[i] || row + col == (g_col[i] + i) || row - col == i - g_col[i])
      return false;
  return true;
}

bool IsSafe(int curRow, int curCol)
{
    int tR, tC;

    for (int i = 0; i < curRow; i++) {
        tR = g_col[i];
        tC = i;
        if (curRow + curCol == tR + tC || curRow - curCol == tC - tR) {
            return false;
        }

        if (g_col[i] != -1 && g_col[i] == curCol) {
            printf("xxxx g_col[%d] = %d, %d\n", i, g_col[i], curCol);
            return false;
        }

    }
    return true;
}
/*
row : 控制深度
col : 每层查看列是否合法
*/
bool GetNQueen(int n, int curRow)
{
    /* terminator */
    if (curRow == n) {
        printf("End\n");
        SaveResult(n, curRow);
        g_ansCnt++;
        return true;
    }

    /* current level logic */
    for (int i = 0; i < n; i++) {
        if (!check(curRow, i)) {
            continue;
        }
        g_col[curRow] = i;
        /* drill down */
        GetNQueen(n, curRow + 1);
        /* revert state */
        //g_col[--curRow] = -1;
    }

    return true;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char *** solveNQueens(int n, int* returnSize, int** returnColumnSizes)
{
    int *colSize;
    char ***ans = NULL;

    g_head.next = NULL;
    g_tail = &g_head;
    g_ansCnt = 0;
    g_col = calloc(n + 1, sizeof(int));

    /* 0 is used to backtrace defualt value */
    GetNQueen(n, 0);
    colSize = calloc(g_ansCnt, sizeof(int));
    ans = calloc(g_ansCnt, sizeof(char **));

    printf("g_ansCnt %d\n", g_ansCnt);
    int k = 0;
    Node *p = g_head.next;
    while (p != NULL) {
        ans[k] = p->g;
        colSize[k] = n;
        printf("ssssss\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%c", ans[k][i][j]);
            }
            printf("\n");
        }
        printf("eeeeeeee\n");
        ++k;
        p = p->next;
    }
    printf("save result \n");

    *returnSize = g_ansCnt;
    *returnColumnSizes = colSize;
    return ans;
}

// @lc code=end

