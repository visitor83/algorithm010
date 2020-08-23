/*
 * @lc app=leetcode.cn id=264 lang=c
 *
 * [264] 丑数 II
 */

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */ 
#define NMAX        2000
int nthUglyNumber(int n) {
    int *arr, *p2, *p3, *p5;
    int nextNum;

    arr = calloc(NMAX, sizeof(int));
    arr[0] = 1;
    p2 = arr; p3 = arr; p5 = arr;

    nextNum = 1;
    while (nextNum < n) {
        // ????, ????
        int temp = fmin((*p2) *2, fmin((*p3) * 3, (*p5) * 5));
        arr[nextNum] = temp;
        // arr [0.. nextNum] * ??p2, p3, p5, ???t *p2 > temp
        while ( (*p2) * 2 <= temp) {
            p2++;
        }
        while ( (*p3) * 3 <= temp) {
            p3++;
        }
        while ( (*p5) * 5 <= temp) {
            p5++;
        }
        nextNum++;
    }
    return arr[nextNum - 1];
}

/*
int main(int argc, char const *argv[])
{
    printf("\nans = %d \n", nthUglyNumber(10));
    return 0;
}
*/


// @lc code=end