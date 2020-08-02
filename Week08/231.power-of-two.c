/*
 * @lc app=leetcode.cn id=231 lang=c
 *
 * [231] 2的幂
 */

// @lc code=start

bool isPowerOfTwo(int m){
    int cnt = 0;
    unsigned int n = (unsigned int )m;
    while (n) {
        cnt++;
        n = n & (n -1);
    }
    return cnt == 1 ? true : false;
}
// @lc code=end

