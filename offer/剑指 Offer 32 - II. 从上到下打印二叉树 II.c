
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

typedef struct tagNode {
    struct TreeNode * tn;
    struct tagNode *next;
} Node;

typedef struct tagQueue{
    Node *front, *rear;
    int qsize;
} Queue;

Queue * QCreate() {
    Queue *q = calloc(1, sizeof(Queue));
    q->front = q->rear = calloc(1, sizeof(Node));
    return q;
}

void QPush(Queue *q, struct TreeNode *tn) {
    Node *n = calloc(1, sizeof(Node));
    n->tn = tn;
    q->rear->next = n;
    q->rear = n;
    ++(q->qsize);
}

Node *QPop(Queue *q) {
    Node *n = q->front->next;
    q->front->next = n->next;
    if (n == q->rear) {
        q->rear = q->front;
    }
    --(q->qsize);
    return n;
}

bool QIsempty(Queue *q) {
    return q->qsize == 0 ? true : false;
}

#define MAX_LEAF_NUM    1010
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int **ans, cnt;
    Queue *qhead;

    cnt = 0;
    ans = calloc(MAX_LEAF_NUM, sizeof(int *));
    *returnColumnSizes = calloc(MAX_LEAF_NUM, sizeof(int));

    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    qhead = QCreate();
    QPush(qhead, root);
    while (!QIsempty(qhead)) {
        int qsize = qhead->qsize;
        int j = 0;

        //printf("qsize %d\n", qsize);
        ans[cnt] = calloc(qsize, sizeof(int));
        (*returnColumnSizes)[cnt] = qsize;

        while (qsize--) {
            Node *pnode = QPop(qhead); 
            struct TreeNode * cur= pnode->tn;

            if (cur) { 
                ans[cnt][j++] = cur->val; 
                //printf("Error\n");
            }

            if (cur->left) { QPush(qhead, cur->left); }
            if (cur->right) { QPush(qhead, cur->right); }
        }
        cnt++;
    }

    *returnSize = cnt;
    return ans;
}