/*
 * @lc app=leetcode.cn id=1122 lang=c
 *
 * [1122] 数组的相对排序
 */

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// 只有交换才可以改变两个元素的前后顺序，稳定性： 当有相邻元素相等，不交换
#define N 1010
int SortAZ (const void *p1, const void *p2) {
    return *(int*)p1 < *(int *)p2 ? -1 : 1;
}
int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize){
    int stats[N] = {0}, i, k;
    int *ans;
/*
    if (!arr1Size || !arr2Size) {
        return 
    }
*/
    ans = calloc(N, sizeof(int));
    for (i = 0; i < arr1Size; i++) {
        stats[arr1[i]]++;
    }

    for (i = 0, k = 0; i < arr2Size; i++) {
        if (stats[arr2[i]]) {
            while (stats[arr2[i]]-- ) {
                ans[k++] = arr2[i];
            }
        }
    }
    int s = k;
    for (i = 0; i < N; i++) {
        if (stats[i] > 0) {
            while (stats[i]--) {
                ans[k++] = i;
            }
        }
    }

    qsort(&ans[s], k - s, sizeof(int), SortAZ);
    *returnSize = k;
    return ans;
}

// @lc code=end

