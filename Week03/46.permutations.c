/*
 * @lc app=leetcode.cn id=46 lang=c
 *
 * [46] 全排列
 */

// @lc code=start


typedef struct tagNode {
    int *arr;
    struct tagNode *next;
} Node;
Node g_head;
Node *g_tail;
int g_ansCnt;

void AddNode (int *stk, int dep)
{
    Node *n = calloc(1, sizeof(Node));
    n->arr = calloc(dep + 1, sizeof(int));
    memcpy(n->arr, stk, dep * sizeof(int));
    g_tail->next = n;
    g_tail = n;
}

void P(int *nums, int numsSize, char *used, int start, int *stk, int dep)
{
    /* terminator */
    if (dep == numsSize) {
        AddNode(stk, dep);
        g_ansCnt++;
        return ;
    }

    /* current level logic */
    for (int i = 0; i < numsSize; i++) {
        if (used[i]) {
            continue;
        }

        used[i] = true;
        stk[dep++] = nums[i];
        /* drill down*/
        P(nums, numsSize, used,  0, stk, dep);
        /* revert the state*/
        stk[--dep] = 0;
        used[i] = false;
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    int i;
    int **ans;
    int *stk;
    char *used;

    if (!nums || numsSize < 0) {
        *returnSize = 0;
        ans = calloc(1, sizeof(int *));
        ans[0] = calloc(1, sizeof(int));
        return ans;
    }

    g_head.next = NULL;
    g_tail = &g_head;
    g_ansCnt = 0;
    stk = calloc(numsSize, sizeof(int));
    used = calloc(numsSize, sizeof(char));

    P(nums, numsSize, used, 0, stk, 0);

    i = 0;
    Node *p;
    ans = calloc(g_ansCnt, sizeof(int *));
    *returnColumnSizes = calloc(g_ansCnt, sizeof(int));
    p = g_head.next;
    while (p) {
        ans[i] = p->arr;
        (*returnColumnSizes)[i] = numsSize;
        i++;
        p = p->next;
    }
    free(stk);
    *returnSize = g_ansCnt;
    return ans;
}
// @lc code=end

