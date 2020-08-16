/*
 * @lc app=leetcode.cn id=72 lang=c
 *
 * [72] 编辑距离
 */

// @lc code=start

/*
int wlen1, wlen2;
int myfunc(char *word1, char *word2, int i, int j) {
  if (i == wlen1) {
    return wlen2 - j;
  }
  if (j == wlen2) {
    return wlen1 - i;
  }
  if (word1[i] == word2[j]) {
      return myfunc(word1, word2, i+1, j+1);
  }
  int d1, d2, d3;
  d1 = myfunc(word1, word2, i + 1, j);
  // 增加
  d2 = myfunc(word1, word2, i, j + 1);
  // 替换
  d3 = myfunc(word1, word2, i + 1, j + 1);
  return fmin(d1, fmin(d2, d3)) + 1;
}
int minDistance(char *word1, char *word2) { 
    wlen1 = strlen(word1);
    wlen2 = strlen(word2);
    return myfunc(word1, word2, 0, 0); 
    }
    */

int wlen1, wlen2;
int myfunc(char *word1, char *word2, int i, int j, int **dp) {
  if (i == wlen1) {
    return wlen2 - j;
  }
  if (j == wlen2) {
    return wlen1 - i;
  }
  if (dp[i][j]) { return dp[i][j]; }

  if (word1[i] == word2[j]) {
      return dp[i][j] = myfunc(word1, word2, i+1, j+1, dp);
  }
  int d1, d2, d3;
  d1 = myfunc(word1, word2, i + 1, j, dp);
  // 增加
  d2 = myfunc(word1, word2, i, j + 1, dp);
  // 替换
  d3 = myfunc(word1, word2, i + 1, j + 1, dp);
  return dp[i][j] = fmin(d1, fmin(d2, d3)) + 1;
}
int minDistance(char *word1, char *word2) { 
    int **dp;
    wlen1 = strlen(word1);
    wlen2 = strlen(word2);
    dp = calloc(wlen1 + 1, sizeof(int*));
    for (int i = 0; i < wlen1; i++) {
        dp[i] = calloc(wlen2 + 1, sizeof(int));
    }
    return myfunc(word1, word2, 0, 0, dp); 
 }

// @lc code=end

