/*
 * @lc app=leetcode.cn id=76 lang=c
 *
 * [76] 最小覆盖子串
 */

// @lc code=start


// "ADOBECODEBANC"
/*
 ADOBEC
  DO
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

char *minWindow(char *s, char *t)
{
    /* 子问题(i, j) 包含t的区间，
    每次怎么更新这个区间， 左边区间跳到上次 t的第二字符出现位置。
    右区间更新： 已求解最小值则+1，
    */
    int map_t[256] = {0};
    int slidingWin[256] = {0};
    int tlen = strlen(t);
    int i, j,  matchCnt;
    int tcharTypeCnt;
    int minLen;
    int start, end;

    if (strlen(t) > strlen(s)) {
        return "";
    }

    tcharTypeCnt = 0;
    for (i = 0; i < tlen; i++) {
        if (!map_t[t[i]]) {
            tcharTypeCnt++;
        }
        map_t[t[i]]++;
    }
    i = 0;
    j = 0;
    matchCnt = 0;
    minLen = INT_MAX; 
    end = start = 0;
    while (j < strlen(s)) {
        char ch = s[j];
        j++;
        if (map_t[ch] != 0) {
            slidingWin[ch]++;

            // 更新条件 当s 中 ch字符与 t中字符个数相同,一个字符匹配成功
            if (slidingWin[ch] == map_t[ch]) {
                matchCnt++;
            }
        }

        while (matchCnt == tcharTypeCnt) {
            //printf("mach hit (%d, %d)\n", i, j);
            if (minLen > j - i) {
                start = i;
                end = j;
                minLen = j - i;
            }
            int chaf = s[i];
            i++;
            // 左侧不再缩小的截止条件 matchCnt减小不再与s匹配
            if (map_t[chaf]) {
                if (slidingWin[chaf] == map_t[chaf]) {
                    matchCnt--;
                }
                slidingWin[chaf]--;
            }
        }
    }
    if (minLen != INT_MAX) {
        char *resBuf = calloc(minLen +1, sizeof(char));
        memcpy(resBuf, s+start, sizeof(char) * minLen);
        return resBuf;
    } else{
        return "";
    }
}
/*
int main(int argc, char const *argv[])
{
    char S[] = "ADOBECODEBANC";
    char T[] = "ABC";

    printf("%s\n", minWindow(S, T));
    return 0;
}
*/

// @lc code=end

