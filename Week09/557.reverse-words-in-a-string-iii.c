/*
 * @lc app=leetcode.cn id=557 lang=c
 *
 * [557] 反转字符串中的单词 III
 */

// @lc code=start
void Swap(char *s, int lo, int hi) {
    char chaf;
    int i, j;
    for (i = lo, j = hi; i <=j; i++, j--) {
        chaf = s[i]; s[i] = s[j]; s[j] = chaf;
    }
}

char * reverseWords(char * s){
    int i, slen, j;
    bool isSwap = false;

    i = 0;
    slen = strlen(s);
    if (slen <= 1) {
        return s;
    }

    while (i < slen) {
        isSwap = false;
        if (isspace(s[i])) {
            i++;
            continue;
        }

        for (j = i; j < slen ; j++ ) {
            if ((j  == slen - 1 || isspace(s[j+1]))  && !isspace(s[j]) ) {
                isSwap = true;
                Swap(s, i, j);
                break;
            }
        }

        if (isSwap) {
            i = j + 1;
        } else {
            i++;
        }
    }

    return s;
}

// @lc code=end

