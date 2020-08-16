/*
 * @lc app=leetcode.cn id=905 lang=c
 *
 * [905] 按奇偶排序数组
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 // 置换 , i之前都是偶数 , j 之后都是奇数
 //  截至条件 i = j  ， 想荷兰国旗问题

 void Swap(int *a, int i, int j) {
     int t;
     t = a[i]; a[i] = a[j]; a[j] = t;
}
int* sortArrayByParity(int* A, int ASize, int* returnSize){
    int i, j;
    if (!A || ASize <= 1) {
        *returnSize = ASize;
        return A;
    } 
    i = 0; j = ASize - 1;
    while (i < j) {
        if (A[i] & 1) {
            // 与 j 的下一个换， 然后不动,
            Swap(A, i, j);
            j--;
        } else if (!(A[i] & 1)) {
            // 偶数
            i++;
        }
    }
    *returnSize = ASize;
    return A;
}


// @lc code=end

