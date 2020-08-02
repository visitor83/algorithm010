/*
 * @lc app=leetcode.cn id=493 lang=c
 *
 * [493] 翻转对
 */

// @lc code=start



//解法1：标准归并排序
/* return the count of left or right side reverse pairs */
int mergeSort(int *nums, int lo, int hi) {
    if (lo >= hi) {
        return 0;
    }
    int m, count, i, j, t, c;
    int *arr;
    m = lo + ((hi - lo)>>1);
    count = mergeSort(nums, lo, m) + mergeSort(nums, m+1, hi);
    // merge and cal the reverse pair between left and right side
    i = lo; t = lo; c = 0;
    arr = calloc(hi - lo + 1, sizeof(int));
    for (j = m+1; j <= hi ; j++) {
        while (i <=m && (long)nums[i] <= (long)2 * nums[j]) {i++;}
        // merge sort a-z
        while (t <=m && nums[t] < nums[j]) { arr[c++] = nums[t++]; }
        arr[c++] = nums[j];
        count += m - i + 1;
    }
    while (t <= m) { arr[c++] = nums[t++];}
    memcpy(&nums[lo], arr, (hi - lo + 1) * sizeof(int));
    free(arr);
    return count;
}
int reversePairs(int* nums, int numsSize){
    return mergeSort(nums, 0, numsSize - 1);
}

//解法2, nlog(n) * log(n) 快速排序增加时间复杂度
int SortAZ(const void *p1, const void *p2) {
    return  *(int *)p1 <  *(int *)p2 ? -1 : 1;
}
int mergeSort( int *nums, int lo, int hi ) {
    int m, lcnt, rcnt;

    if (lo >= hi) { return 0; }

    lcnt =0; rcnt = 0;
    m = lo + ((hi - lo) >>1 );

    lcnt += mergeSort(nums, lo, m);
    rcnt += mergeSort(nums, m + 1, hi);

    int i, j, res;
    res = 0;
    for (i = lo, j = m + 1;  i <= m; i++) {
        while (j <= hi && (long)nums[i] > (long)nums[j] * 2) {
            j++;
        } 
        res += j -( m  + 1);
    }
    qsort(&nums[lo], hi - lo + 1, sizeof(int), SortAZ);
    return res + lcnt + rcnt;
}

int reversePairs(int* nums, int numsSize){
    if (numsSize <= 0 || !nums) {
        return 0;
    }
    return mergeSort(nums, 0, numsSize - 1);
}

// @lc code=end

