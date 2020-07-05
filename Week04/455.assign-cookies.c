/*
 * @lc app=leetcode.cn id=455 lang=c
 *
 * [455] 分发饼干
 */

// @lc code=start

int Sort(const void *p1, const void *p2)
{
    int a = *(int *)p1, b = *(int*)p2;
    return a < b ? -1 : 1;
}

int findContentChildren(int* g, int gSize, int* s, int sSize)
{
    // subproblem what ? s(j) >= g(i) 分配原则
    // 分配饼干，重复子问题怎么做？ 选择刚好g(i)胃口的饼干分给child
    // big problem is 尽可能多满足越多数量孩子  

    int i, j;
    int ans = 0;

    if (gSize <= 0 || sSize <= 0) {
        return 0;
    }

    qsort(g, gSize, sizeof(int), Sort);
    qsort(s, sSize, sizeof(int), Sort);

    i = 0;
    for (j = 0; i < gSize &&  j < sSize; j++) {
        if (s[j] >= g[i]) {
            i++;
            ans++;
        }
    }
    return ans;
}
// @lc code=end

