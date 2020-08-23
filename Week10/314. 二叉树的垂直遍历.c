
typedef struct tagNode {
    struct TreeNode * tn;
    int posi;
    struct tagNode *next;
} Node;

typedef struct tagMap {
    int posi;
    Node *node;
    Node *tail;
    int cnt;
    UT_hash_handle hh;
} Map;

typedef struct tagQueue {
    Node *front, *rear;
    int qsize;
} Queue;

Queue *QCreate() {
    Queue *q = calloc(1, sizeof(Queue));
    q->front = q->rear = calloc(1, sizeof(Node));
    q->qsize = 0;
    return q;
}
void QPush(Queue *q, struct TreeNode *tn, int posi) {
    Node *n = calloc(1, sizeof(Node));
    n->tn= tn;
    n->posi = posi;
    q->rear->next = n;
    q->rear = n;
    ++(q->qsize);
}
Node *QPop(Queue *q) {
    Node *n = q->front->next;
    q->front->next = n->next;
    if (q->rear == n) {
        q->rear = q->front;
    }
    --(q->qsize);
    return n;
}
bool QIsEmpty(Queue *q) {
    return (q->qsize == 0) ? true : false;
}

int HashSortAZ(const void *p1, const void *p2) {
    Map *a = (Map*) p1, *b = (Map*)p2;
    return a->posi  < b->posi ?  -1 : 1;
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** verticalOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    Map *map= NULL;
    Queue *qhead;
    int **ans;
    int posi = 0, ansCnt;

    qhead = QCreate();
    QPush(qhead, root, 0);
    ansCnt = 0;
    while (!QIsEmpty(qhead)) {
        int qsize = qhead->qsize;
        while (qsize--) {
            Node *pNode= QPop(qhead);
            struct TreeNode *cur ;
            Map *ent, *temp = NULL;
            if (!pNode || !pNode->tn){
                continue;
            }
            cur = pNode->tn;
            //printf(" %d %d, ", cur->val, pNode->posi);
            HASH_FIND_INT(map, &pNode->posi, temp);
            if (!temp) {
                ent = calloc(1, sizeof(Map));
                ent->posi = pNode->posi;
                ent->node = pNode;
                pNode->next = NULL;
                ent->tail = ent->node;
                ++ent->cnt;
                ++ansCnt; //printf(" new one %d val %d\n", ent->posi, pNode->tn->val);
                HASH_ADD_INT(map, posi, ent);
            } else {
                //printf("--> %d val %d ; %d %d\n", pNode->posi, pNode->tn->val, 
                //        temp->posi, temp->node->tn->val);
                temp->tail->next = pNode;
                temp->tail= pNode;
                pNode->next = NULL;
                ++temp->cnt;
            }

            if (cur->left) {
                QPush(qhead, cur->left, pNode->posi - 1);
            }
            if (cur->right) {
                QPush(qhead, cur->right, pNode->posi + 1);
            }
        }
        //printf("\n");
    }

    HASH_SORT(map, HashSortAZ); //printf(" ansCnt %d \n", ansCnt);
{
    Map *temp, *iter;
    Node *cur;
    int i = 0, j;
    *returnSize = ansCnt;
    *returnColumnSizes = calloc(ansCnt, sizeof(int));
    ans = calloc(ansCnt, sizeof(int*));

    HASH_ITER(hh, map, iter, temp) {
        if (iter) {
            ans[i] = calloc(iter->cnt, sizeof(int));
            cur = iter->node;
            j = 0;
            while (cur != NULL) {
                ans[i][j++] = cur->tn->val;
                //printf(" %d, ", cur->tn->val);
                cur = cur->next;
            }
            (*returnColumnSizes)[i] = iter->cnt;
            ++i;
        }
        //printf("\n");
    }
}
    return ans;
}