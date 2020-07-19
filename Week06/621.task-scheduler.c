/*
 * @lc app=leetcode.cn id=621 lang=c
 *
 * [621] 任务调度器
 */

// @lc code=start
#define N 26
/*
["A","A","A","A","A","A","B","C","D","E","F","G"]
2
*/
int SortAZ(const void *p1, const void *p2)
{
    return *(int *)p1 < *(int *)p2 ? 1 : -1;
}
int GetRemain(int *a, int n)
{
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (a[i]) {
            res++;
        }
    }
    return  res;
}
int leastInterval(char* tasks, int tasksSize, int n)
{
    int i, j, ans;
    int table[N] = {0};
    if (n == 0) {
        return tasksSize;
    }

    for ( i = 0; i < tasksSize; i++) {
        table[tasks[i] - 'A']++;
    }
    qsort(table, N, sizeof(int), SortAZ);
    ans = 0;

    const int interval = n + 1;
    while (table[0] != 0) {
        int k ;
        int tsize = GetRemain(table, N);
        //printf("tsize %d ans %d, ", tsize, ans);
        k = 0;
        for (j = 1; j <= interval; j++) {
            //  1. table 长度比 n 大,  无停顿
            //  2. table 长度比 n 小， 每次都需要停顿
            //  最后剩余不满n 时，直接跳出  ??
            if (table[0] == 0) {
                break;
            }
            if (table[k]) {
                table[k]--; k++;
            }
            ans++;
        }
        qsort(table, N, sizeof(int), SortAZ);
    }

    return ans;
}

// @lc code=end

