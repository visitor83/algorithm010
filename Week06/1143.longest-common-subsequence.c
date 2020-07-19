/*
 * @lc app=leetcode.cn id=1143 lang=c
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
int GetLCS(char *s1, char *s2, int a, int b, int **dp)
{
    // terminator
    if (a < 0 || b < 0) {
        return 0;
    }

    if (dp[a][b]) {
        return dp[a][b];
    }

    //printf(" (%d, %d)\n", a, b);
    if (s1[a] == s2[b]) {
        return dp[a][b] = GetLCS(s1, s2, a - 1, b -1, dp) + 1;
    }
    int lcsa, lcsb;
    
    // 最优子结构，当前层选择最长的
    lcsa = GetLCS(s1, s2, a - 1, b, dp);
    lcsb = GetLCS(s1, s2, a    , b - 1, dp);

    return dp[a][b] = fmax(lcsa, lcsb);
}

int longestCommonSubsequence(char * text1, char * text2)
{
    int **dp;
    int dplen = fmax(strlen(text1), strlen(text2)) + 10;

    printf("dplen %d\n", dplen);
    dp = calloc(dplen, sizeof(int *));
    for (int i = 0; i < dplen; i++) {
        dp[i] = calloc(dplen, sizeof(int));
    }

    return GetLCS(text1, text2, strlen(text1) - 1, strlen(text2) - 1, dp);
}
// @lc code=end

