/*
 * @lc app=leetcode.cn id=852 lang=c
 *
 * [852] 山脉数组的峰顶索引
 */

// @lc code=start

int peakIndexInMountainArray2(int* A, int ASize){
    int i, j, m, ans;
    i = 0; j = ASize - 1;
    while (i <= j) {
        m = i + ((j - i) >>1);
        if (m + 1 < ASize && A[m] < A[m+1]) {
            i = m + 1;
        } else {
            ans = m;
            j = m - 1;
        }
    }
    return ans;
}

int myfunc(int *a, int lo, int hi) {
    int m = lo + ((hi - lo) >> 1);
    if (a[m] > a[m - 1] && a[m + 1] > a[m]) {
        // right side 
        return myfunc(a, m , hi);
    }
    if (a[m] < a[m - 1] && a[m + 1] < a[m]) {
        return myfunc(a, lo, m);
    }
    return m;
}

int peakIndexInMountainArray(int* A, int ASize){ 
    return myfunc(A, 0, ASize - 1);
}

// @lc code=end

