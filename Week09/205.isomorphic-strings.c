/*
 * @lc app=leetcode.cn id=205 lang=c
 *
 * [205] 同构字符串
 */

// @lc code=start

#define N 256

bool isIsomorphic(char * s, char * t){
    int sl, tl, i, j;
    int m1[N] = {0}, m2[N] = {0};
    sl = strlen(s);
    tl = strlen(t);
    if (sl != tl) {
        return false;
    }
    if (!s && !t) { return true; }
    if (!s || !t) { return false;}

    for (i = 0; i < sl; i++) {
        if (m1[s[i]] != m2[t[i]]) { return false; }
        m1[s[i]] = i+ 1;
        m2[t[i]] = i+ 1;
    }
    return true;
}
// @lc code=end


// @lc code=end

