/*
 * @lc app=leetcode.cn id=50 lang=c
 *
 * [50] Pow(x, n)
 */

// @lc code=start
double myPow(double x, int n)
{
    double res;

    if (n == -1 ) {
        return (double)(1.0/x);
    }

    if (n == 1) {
        return x;
    }

    if (n == 0) {
        return 1;
    }

    res = myPow(x, n/2);
    res *= res;
    if (n % 2 != 0) {
        res *= (n >= 0) ? x : (double)(1.0/x);
    } else {
    }
    return res;
}

// @lc code=end

