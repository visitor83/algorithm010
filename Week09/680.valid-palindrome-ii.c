/*
 * @lc app=leetcode.cn id=680 lang=c
 *
 * [680] 验证回文字符串 Ⅱ
 */

// @lc code=start

bool myfunc(char *s, int lo, int hi, bool flag) {
    int i, j;

    i = lo; j = hi;
    while (i <= j) {
        if (s[i] != s[j] ) {
            // i++ or j-- two ways
            if (!flag) {
                return myfunc(s, i + 1, j, true) || myfunc(s, i, j-1, true);
            } else {
                return false;
            }
        } else {
            i++;
            j--;
        }
    }
    return true;
}

bool validPalindrome(char * s){
    if (!s || strlen(s) <= 1) {
        return true;
    }
    return myfunc(s, 0, strlen(s)-1, false);
}
// @lc code=end

