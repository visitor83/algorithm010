/*
 * @lc app=leetcode.cn id=190 lang=c
 *
 * [190] 颠倒二进制位
 */

// @lc code=start
uint32_t reverseBits(uint32_t n) {
    uint32_t res = 0, step = 31;

    while (n) {
        res |= ( n & 1) << step;
        n = n >> 1;
        step--;
    }
    return res;
}
// @lc code=end

