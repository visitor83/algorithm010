/*
 * @lc app=leetcode.cn id=917 lang=c
 *
 * [917] 仅仅反转字母
 */

// @lc code=start

void Swap(char *s, int i, int j) {
    char chaf;
    chaf =  s[i]; s[i] = s[j]; s[j] = chaf;
}

char * reverseOnlyLetters(char * S){
    int i, j, slen;
    slen = strlen(S);
    if (!S || slen <= 0 ) {
        return S;
    }
    i = 0; j = strlen(S) - 1;
    while (i <= j) {
        if (isalpha(S[i]) && isalpha(S[j])) {
            Swap(S, i, j);
            i++; j--;
        } else {
            if (!isalpha(S[i])) {
                i++;
            }
            if (!isalpha(S[j])) {
                j--;
            }
        }
    }
    return S;
}
// @lc code=end

