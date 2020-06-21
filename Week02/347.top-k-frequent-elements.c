/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdbool.h>
#include <uthash.h>

typedef struct tagMap {
    int val;
    int cnt;
    UT_hash_handle hh;
} Map;

Map *g_mapfreq;

/*
 * compare a to b (cast a and b appropriately)
 * return -1 if (a < b),  a, b
 * return  0 if (a == b)
 * return  1 if (a > b),  b, a
 */
int SortFreqCnt(const void *a, const void *b)
{
    Map *p1 = (Map *)a;
    Map *p2 = (Map *)b;

    return p1->cnt > p2->cnt ? -1 : 1;
}
 
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize)
{
    int i, ansCnt;
    int *ans;
    Map *ent, *iter, *nouse;

    if (numsSize <= 0 || k <= 0) {
        ans = calloc(1, sizeof(int));
        *returnSize = 0;
        return ans;
    }

    g_mapfreq = NULL;
    ans = calloc(k, sizeof(int));
    /* get freq of numes[i] */
    for (i = 0; i < numsSize; i++) {
        HASH_FIND_INT(g_mapfreq, &nums[i], ent);

        if (ent) {
            /* map contain nums[i] (ent->val) */
            ent->cnt++;
        } else {
            ent = calloc(1, sizeof(Map));
            ent->cnt++;
            ent->val = nums[i];
            HASH_ADD_INT(g_mapfreq, val, ent);
        }
    }

    ansCnt = 0;
    HASH_SORT(g_mapfreq, SortFreqCnt);
    HASH_ITER(hh, g_mapfreq, iter, nouse) {
        if (iter != NULL && ansCnt < k) {
            //printf("%d freq[%d], ", iter->val, iter->cnt);
            ans[ansCnt++] = iter->val;
        }
        HASH_DEL(g_mapfreq, iter);
        free(iter);
    }

    *returnSize = k;
    return ans;
}