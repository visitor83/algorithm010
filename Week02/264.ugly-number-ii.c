/*
 * @lc app=leetcode.cn id=264 lang=c
 *
 * [264] 丑数 II
 */

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <uthash.h>

#define NFACTORS    3
#define NUMS        2048

typedef struct tagMap {
    int val;
    UT_hash_handle hh;
} Map;

typedef struct tagPQ {
    int arr[NUMS];
    int size;
} PQ;

PQ *HeapInit()
{
    PQ *pq = calloc(1, sizeof(PQ));
    pq->size = 0;
    return pq;
}

void Swap(PQ *pq, int i, int j)
{
    int t;
    int *arr = pq->arr;
    t = arr[i];  arr[i] = arr[j]; arr[j] = t;
}

/*
 * if a < b, return true;
 */
int Less(PQ *pq, int a, int b)
{
    int *arr = pq->arr;
    return arr[a] < arr[b] ? true : false;
}

void HeapPush(PQ *pq, int val)
{
    int k;

    pq->arr[++pq->size] = val;
    k = pq->size;
    while (k > 1 && Less(pq, k, k / 2)) {
        Swap(pq, k/2, k);
        k = k / 2;
    }
}

/*  pq->arr[0] is not used, sential element */
int HeapPop(PQ *pq)
{
    int top, k, lchild, rchild, smallest;

    /* swap the root and last elemnt, decrease the pq'size */
    top = pq->arr[1];
    Swap(pq, 1, pq->size);
    pq->size--;

    k = 1;
    while ( k * 2  <= pq->size )  {
        /* foud min of (lchild, rchild), the rchild < lchild */
        lchild = k * 2;
        rchild = k * 2 + 1;

        smallest = lchild;
        if ((rchild < pq->size) &&  Less(pq, rchild, lchild)) {
            smallest = rchild;
        }

        /* parent is not smaller than rchild or lchild */
        if (!Less(pq, smallest, k)) {
            break;
        }

        Swap(pq, smallest, k);
        k = smallest;
    }
    return top;
}

Map *g_map;

int nthUglyNumber(int n)
{
    bool found = false;
    int ansCnt;
    int ans, popdata;
    Map *ent;
    PQ *pq;

    if (n == 0 || n == 1) {
        return n;
    }
    ansCnt = 0;
    g_map = NULL;

    pq = HeapInit();

    HeapPush(pq, 1);
    ent = calloc(1, sizeof(Map));
    ent->val = 1;
    HASH_ADD_INT(g_map, val, ent);

    while (!found) {
        popdata = HeapPop(pq);
        ansCnt++;
        printf("%d, ", popdata);
        if (ansCnt == n) {
            ans = popdata;
            found = true;
            break;
        }

        int step[NFACTORS] = {2, 3, 5};
        for (int i = 0; i < NFACTORS; i++) {
            int searchVal = popdata * step[i];

            HASH_FIND_INT(g_map, &searchVal, ent);
            if (!ent) {
                HeapPush(pq, searchVal);

                ent = calloc(1, sizeof(Map));
                ent->val = searchVal;
                HASH_ADD_INT(g_map, val, ent);
            }
        }
    }

    return ans;
}

/*
int main(int argc, char const *argv[])
{
    printf("\nans = %d \n", nthUglyNumber(10));
    return 0;
}
*/


// @lc code=end