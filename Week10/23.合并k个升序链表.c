/*
 * @lc app=leetcode.cn id=23 lang=c
 *
 * [23] 合并K个升序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#define N 20
typedef struct MinPQ_ {
    int cap;
    int size;
    //int a[N];
    int *a;
} MinPQ;

int More(MinPQ *pq, int i, int j)
{
    if (pq->a[i]  > pq->a[j]) {
        return 1;
    }
    return 0;
}

void InitPQ(MinPQ *pq, int maxElement)
{
    pq->cap = maxElement; 
    pq->size = 0;
    pq->a = (int*)malloc(sizeof(int) *maxElement);
    memset(&pq->a[0], 0, sizeof(pq->a));
}

void Swap(MinPQ *pq, int i, int j)
{
    int tmp;
    tmp = pq->a[i];
    pq->a[i] = pq->a[j];
    pq->a[j] = tmp;
}

void Swin(MinPQ *pq, int k)
{
    while (k > 1 && (More(pq, k/2, k) == 1)) {
        Swap(pq, k/2, k);
        k = k / 2;
    }
}

void Insert(MinPQ *pq, int data)
{
    if (pq->size > pq->cap) {
        printf("Full capcity %d\n", pq->cap);
    }
    pq->a[++pq->size] = data;
    Swin(pq, pq->size);
}

void Sink(MinPQ *pq, int k)
{
    int left;
    while (k * 2 <= pq->size) {
        left = k * 2;
        if ((left < pq->size) && (More(pq, left, left + 1) ==1)) {
            left = left+1;
        }
        if (More(pq, k, left) == 0) { break; }
        Swap(pq, k, left);
        k = left;
    }
}

int Del(MinPQ *pq, int *data)
{
    int d;
    if (pq->size == 0) {
        printf("Empty size %d\n", pq->size);
        return 1;
    }
    d = pq->a[1];
    Swap(pq, 1, pq->size--);
    Sink(pq, 1);
    *data = d;
    return 0;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{
    int i;
    int cnt;
    int min;
    MinPQ PQ;
    struct ListNode *pC, *pTail, *pNode;
    struct ListNode dummy;

    cnt = 0;
    for (i = 0; i < listsSize; i++) {
        pC = lists[i];
        while (pC != NULL) {
            //Insert(&PQ, pC->val);
            cnt++;
            pC = pC->next;
        }
    }

    InitPQ(&PQ, cnt+2);
    //printf("listSize %d\n", listsSize);
    for (i = 0; i < listsSize; i++) {
        pC = lists[i];
        while (pC != NULL) {
            Insert(&PQ, pC->val);
            pC = pC->next;
        }
    }
    dummy.next = NULL;
    pTail = &dummy;
    while ((Del(&PQ, &min) == 0) ) {
        //printf("%d-->", min);
        pNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        pNode->val = min;   pNode->next = NULL;     
        pTail->next = pNode;
        pTail = pNode;
        ++cnt;
    }
    return dummy.next;
}

// @lc code=end

