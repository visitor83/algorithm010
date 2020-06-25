/*
 * @lc app=leetcode.cn id=78 lang=c
 *
 * [78] 子集
 */

// @lc code=start

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define VISITED 2

typedef struct tagNode {
    int *arr;
    int arrSize;
    struct tagNode *next;
} Node;

Node g_head;
Node *g_tail;
int g_ansCnt;

void AddNode (int *stk, int dep)
{
    Node *n = calloc(1, sizeof(Node));
    n->arr = calloc(dep, sizeof(int));
    n->arrSize = dep ;
    memcpy(n->arr, stk, dep * sizeof(int));
    g_tail->next = n;
    g_tail = n;
}

void Helper(int *nums, int numsSize, int range, int start, int *stk,  int dep)
{
    /* terminator */
    if (dep == range) {
        /*
        printf("dep %d, rang %d\n", dep, range);
        for (int j = 0; j < dep; j++) {
            printf("%d,", stk[j]);
        }
        printf("\n");
        */
        g_ansCnt++;
        AddNode(stk, dep);
        return ;
    }
    
    /* currrent logic */
    for (int i = start; i < numsSize; i++) {
        stk[dep++] = nums[i];
        /* drill down*/
        Helper(nums, numsSize, range, i + 1,  stk, dep);
        /* reverse current state */
        stk[--dep] = 0;
    }
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    Node *p;
    int i;
    int *stk;
    int **ans;
    int *colSize;

    stk = calloc(numsSize + 1, sizeof(int));
    
    g_tail = &g_head;
    g_ansCnt = 0;

    for (int step = 0; step <= numsSize; step++) {
        Helper(nums, numsSize, step , 0,  stk, 0);
    }

    i = 0;
    ans = calloc(g_ansCnt, sizeof(int *));
    colSize = calloc(g_ansCnt, sizeof(int));

    p = g_head.next;
    while (p) {
        ans[i] = p->arr;
        colSize[i] =p->arrSize;
        i++;
        p = p->next;
    }
    *returnColumnSizes = colSize;
    *returnSize = g_ansCnt;
    return ans;
}
// @lc code=end

