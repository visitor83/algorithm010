/*
 * @lc app=leetcode.cn id=77 lang=c
 *
 * [77] 组合
 */

// @lc code=start

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
typedef struct tagNode {
    int *arr;
    int arrSize;
    struct tagNode *next;
} Node;

int g_ansCnt;
Node g_head, *g_tail;

void AddNode (int *stk, int dep)
{
    Node *n = calloc(1, sizeof(Node));
    n->arr = calloc(dep, sizeof(int));
    n->arrSize = dep ;
    memcpy(n->arr, stk, dep * sizeof(int));
    g_tail->next = n;
    g_tail = n;
}

void PrintC(int *stk, int dep)
{
    for (int i = 0; i < dep; i++) {
        printf("%d, ", stk[i]);
    }
    printf("\n");
}

void C(int n, int k, int start, int *stk, int dep)
{
    /* terminator */
    if (dep == k ) {
        AddNode(stk, dep);
        PrintC(stk, dep);
        ++g_ansCnt;
        return ;
    }

    //printf("start %d\n", start);
    /* current level logic */
    for (int i = start; i <= n; i++) {
        /* drill down */
        stk[dep++] = i;
        C(n, k, i + 1, stk, dep);
        stk[--dep] = 0;
    }
    /* revert state */
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes)
{
    int *stk;
    int **ans;

    stk = calloc(n + 1, sizeof(int));
    g_ansCnt = 0;
    g_tail = &g_head;

    C(n, k, 1, stk, 0);

    Node *node;
    int i;

    i = 0;  
    node = g_head.next;
    ans = calloc(g_ansCnt, sizeof(int*));
    *returnColumnSizes = calloc(g_ansCnt, sizeof(int));
    while (node) {
        ans[i] = node->arr;
        (*returnColumnSizes)[i] = node->arrSize;
        i++;
        node = node->next;
    }

    *returnSize = g_ansCnt;
    return ans;
}


// @lc code=end

