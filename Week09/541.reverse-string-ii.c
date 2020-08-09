/*
 * @lc app=leetcode.cn id=541 lang=c
 *
 * [541] 反转字符串 II
 */

// @lc code=start


int g_slen;
void DoReverse(char *s, int lo, int hi) {
    int i, j;
    //printf(" --> lo %d, hi %d\n", lo, hi);
    for (i = lo, j = hi; i <= j; i++, j--) {
        char chaf = s[i]; s[i] = s[j]; s[j]= chaf;
    }
}
char * myfunc( char *s, int j, int k) {
    int i;
    //terminator
    if (j >= g_slen) {
        return s;
    }

    for (i = j ; i < j+2*k && i < g_slen; i++) {
        if (i == j + k - 1) {
            DoReverse(s, j , i);
        } 
    }
    // 如果剩余字符少于k，全部反转
    if (i < j + k) {
        DoReverse(s, j, g_slen - 1);
    }
    return myfunc(s, i, k);
}

char * reverseStr(char * s, int k){
    if (!s || k <= 1) {
        return s;
    }
    g_slen = strlen(s);
    return myfunc(s, 0, k);
}
// @lc code=end

