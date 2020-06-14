//#define N     20
#define TRUE  0
#define FALSE 1

typedef struct tagQ {
    int front;
    int rear;
    int size, cap;
    int *data;
    //int data[N];
} Q;

Q g_queue;

void Init(Q *pq, int maxSize)
{
    pq->size = 0;
    pq->front = 1;
    pq->rear = 0;
    pq->cap = maxSize + 1;

    pq->data = (int *)malloc(sizeof(int) * maxSize);
    memset(&pq->data[0], 0, sizeof(int) * maxSize);
}

void DeQTail(Q *pq)
{
    pq->data[pq->rear] = 0;
    pq->size--;
    pq->rear--;
}

int IsEmpty(Q *pq)
{
    return pq->size == 0 ? TRUE : FALSE;
}

int IsFull(Q *pq)
{
    return pq->size == pq->cap ? TRUE : FALSE;
}

int GetQMax(Q *pq)
{
    if (IsEmpty(pq) == TRUE) {
        printf("GetMax Empty\n");
        return 0;
    }
    return  pq->data[pq->front];
}

int PeekTail(Q *pq)
{
    return pq->data[pq->rear];
}

int PeekHead(Q *pq)
{
    return pq->data[pq->front];
}

void EnQ(Q *pq, int *nums, int curr)
{
    while (IsEmpty(pq) != TRUE && nums[curr] > PeekTail(pq)) {
        DeQTail(pq);
    }

    if (IsFull(pq) == TRUE) {
        printf("Q is full size %d\n", pq->cap);
        return ;
    }

    pq->data[++pq->rear] = nums[curr];
    ++pq->size;
}

void DeQ(Q *pq, int *nums, int curr, int k)
{
    if (IsEmpty(pq) != TRUE && nums[curr - k + 1] == PeekHead(pq)) {
        --pq->size;
        pq->data[pq->front] = 0;
        ++pq->front;
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize)
{
    int i, j;
    int *ans;
    Q *pq = &g_queue;

    Init(pq, numsSize + 1);

    ans = (int *)malloc(sizeof(int) * numsSize);
    
    for (i = 0, j= 0; i < numsSize; i++) {
        if (i < k - 1) {
            EnQ(pq, nums, i);
        } else {
            EnQ(pq, nums, i);
            int tmp;
            tmp = GetQMax(pq);
            //printf("%d --> ", tmp); 
            ans[j++] = tmp;
            DeQ(pq, nums, i, k);
        }
    }
    *returnSize = j;
    return ans;
}