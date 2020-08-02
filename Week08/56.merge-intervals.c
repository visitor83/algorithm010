/*
 * @lc app=leetcode.cn id=56 lang=c
 *
 * [56] 合并区间
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int SortAZ(const void *p1, const void *p2)
{
    int *a = *(int**)p1, *b = *(int**)p2;
    return a[0] < b[0] ? -1 :1;
}
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    int **ans;
    int i, j;

    if (intervalsSize == 0 || !intervals) {
        *returnSize = 0;
        return NULL;
    }

    ans = calloc(intervalsSize, sizeof(int*));
    for (i = 0; i < intervalsSize; i++) {
        ans[i] = calloc(2, sizeof(int));
    }
    qsort(intervals, intervalsSize, sizeof(int*), SortAZ);

    for (i = 0, j = 0; i < intervalsSize; i++) {
        if (i == 0) { 
            ans[j][0] = intervals[i][0]; ans[j][1] = intervals[i][1]; 
            continue;
        }
        if (intervals[i][0] <= ans[j][1]) {            
            ans[j][1]  = fmax(ans[j][1], intervals[i][1]);
        } else {
            ++j;
            ans[j][0] = intervals[i][0];
            ans[j][1] = intervals[i][1];
        }
    }
    j++;

    *returnSize = j;
    (*returnColumnSizes) = calloc(j , sizeof(int));
    for (i = 0; i < j; i++) {
        (*returnColumnSizes)[i] = 2;
    }

    return ans;
}


// @lc code=end

