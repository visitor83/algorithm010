/*
 * @lc app=leetcode.cn id=977 lang=c
 *
 * [977] 有序数组的平方
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/*
int SortAZ(const void *p1, const void *p2) {
    int a = *(int*)p1, b = *(int *)p2;
    return a*a < b*b ? -1 :1; 
}
int* sortedSquares(int* A, int ASize, int* returnSize){
    if (!A) {
        *returnSize = ASize;
        return A;
    }
    qsort(A, ASize , sizeof(int), SortAZ);
    for (int i = 0; i < ASize; i++) {
        A[i] *= A[i];
    }
    *returnSize = ASize;
    return A;
}
*/
/* 分成两部分递增，类似两个排序数组合并问题 */
int* sortedSquares(int* A, int ASize, int* returnSize){ 
    int i, j;
    int *ans;

    if (!A) {
        *returnSize = 0;
        return A;
    }

    for (i = 0; i < ASize; i++) {
        if (A[i] >= 0) {
            break;
        }
    }
    int pvoit = i, k = 0;
    ans = calloc(ASize + 1, sizeof(int));
    for (i = pvoit - 1, j = pvoit; i >= 0 && j < ASize; ) {
        if (A[i] * A[i] <  A[j] * A[j]) {
            ans[k++] = A[i] * A[i];
            i--;
        } else {
            ans[k++] = A[j] * A[j];
            j++;
        }
    }
    while (i >= 0) {
        ans[k++] = A[i] * A[i]; i--;
    }
    while (j <  ASize) {
        ans[k++] = A[j] * A[j]; j++;
    }
    *returnSize = ASize;
    return ans;
}


// @lc code=end

