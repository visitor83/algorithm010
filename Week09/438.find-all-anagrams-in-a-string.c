/*
 * @lc app=leetcode.cn id=438 lang=c
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define N 256
int* findAnagrams(char * s, char * p, int* returnSize){
    int i, j, slen;
    int *ans, ansCnt, matchCnt, numChasOfP;
    int mapat[N] ={0}, sliding[N] = {0};

    if (!s || !p ) {
        return NULL;
    }
    i = 0; slen = strlen(s);
    j = 0; ansCnt = 0;
    ans = calloc(slen + 10, sizeof(int));
    for (j = 0, numChasOfP = 0; j < strlen(p); j++) {
        if (!mapat[p[j]]) {
            numChasOfP++;
        }
        mapat[p[j]]++;
    }
    matchCnt = 0;
    bool found = false;
    for (j = 0, ansCnt = 0; j < slen; j++) {
        if (!mapat[s[j]]) {
            memset(sliding, 0, sizeof(int) * N);
            matchCnt = 0;
            found = true;
            continue;
        }
        sliding[s[j]]++;
        i = found ?  j : i;
        //printf(" ---> j %d i %d, match %d\n", j, i, matchCnt);
        if (sliding[s[j]] == mapat[s[j]]) {
            matchCnt ++;
            //printf("xxx j %d\n", j);
            while (matchCnt == numChasOfP) {
                //printf(" j %d i %d\n", j, i);
                ans[ansCnt++] = i;
                if (mapat[s[i]] ) {
                    matchCnt--;
                }
                sliding[s[i]]--;
                i++;
            }
            found = matchCnt == 0 ? true : false;
        } else if (sliding[s[j]] > mapat[s[j]]) {
            //printf("$$$ j %d\n", j);
            while (sliding[s[j]] > mapat[s[j]]) {
                if (sliding[s[i]] == mapat[s[i]]) {
                    matchCnt--;
                }
                sliding[s[i]]--;
                i++;
            }
            found = matchCnt == 0 ? true : false;
        }
        found = false;
    }
    *returnSize = ansCnt;
    return ans;
}
// @lc code=end

// @lc code=end

