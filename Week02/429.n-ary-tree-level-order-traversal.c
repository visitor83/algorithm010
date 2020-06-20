/*
 * @lc app=leetcode.cn id=429 lang=c
 *
 * [429] N叉树的层序遍历
 */

// @lc code=start
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */
#define MAX_NODE    6000
#define MAX_DEP     1010
struct Node *g_queue[MAX_NODE];
int g_front, g_rear, g_qsize;

void Init()
{
    g_front = g_rear = 0;
    g_qsize = 0;
}

void Enq(struct Node *n)
{
    g_queue[g_rear] = n;
    g_rear = (g_rear + 1) % MAX_NODE;
    g_qsize++;
}

struct Node *Deq()
{
    struct Node *n;
    n = g_queue[g_front];
    g_front = (g_front + 1) % MAX_NODE;
    g_qsize--;
    return n;
}

int GetQsize()
{
    return g_qsize;
}

bool IsEmpty()
{
    return g_front == g_rear ? true : false;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct Node* root, int* returnSize, int** returnColumnSizes) 
{
    int ** ans;
    int ansCnt;
    int *colSize;
    int col;
    struct Node *deqNode;

    ansCnt = 0;
    ans = calloc(MAX_DEP, sizeof(int));
    colSize = calloc(MAX_DEP, sizeof(int));
    if (!root) {
        colSize[0] = 0;
        *returnColumnSizes = colSize;
        *returnSize = ansCnt;
        return ans;
    }
    Enq(root);
    while (!IsEmpty()) {
        int qsize = GetQsize(); 
        ans[ansCnt] = calloc(qsize, sizeof(int));
        colSize[ansCnt] = qsize;

        //printf(" qsize %d\n", qsize);

        col = 0;
        for (int i = 0; i < qsize; i++) {
            deqNode = Deq();
            ans[ansCnt][col++] = deqNode->val;
            for (int j = 0; j < deqNode->numChildren; j++) {
                Enq(deqNode->children[j]);
            }
        }
        ansCnt++;
    }

    *returnColumnSizes = colSize;
    *returnSize = ansCnt;
    return ans;
}
// @lc code=end

