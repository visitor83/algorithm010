/*
 * @lc app=leetcode.cn id=241 lang=c
 *
 * [241] 为运算表达式设计优先级
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *myfunc(char *s, int start, int end, int slen, int *res, int *returnSize) {
  // terminal
  int i, count = 0, num = 0;

  *returnSize = 0;
  for (i = start; i < end && isdigit(s[i]); i++) {
      num = num *10 + (s[i] - '0');
  }

  if (i >= end) {
    res[count++] = num;
    *returnSize = count;
    return res;
  }
  for (i = start; i < end; i++) {
    if (isdigit(s[i])) {
      continue;
    }
    char opType = s[i];
    int *a, *b;
    int alen = 0, blen = 0, l, r;

    a = calloc(slen, sizeof(int));
    b = calloc(slen, sizeof(int));
    a = myfunc(s, start, i, slen, a, &alen);
    b = myfunc(s, i+1, end, slen, b, &blen);
    for (l = 0; l < alen; l++) {
        for (r = 0; r < blen; r++) {
            if (count >= slen) {
                res = realloc(res, (count << 1) * sizeof(int));
            }
            switch (opType) {
                case '+': res[count++] = a[l] + b[r]; break;
                case '*': res[count++] = a[l] * b[r]; break;
                case '-': res[count++] = a[l] - b[r]; break;
            }
        }
    }
    free(a);
    free(b);
  }
  *returnSize = count;
  return res;
}

int* diffWaysToCompute(char * input, int* returnSize){
  int *ans;
  int slen;

  *returnSize = 0; 
  slen = strlen(input);
  ans = calloc(slen *slen *slen, sizeof(int));
  ans = myfunc(input, 0, slen, slen*slen*slen, ans, returnSize);
  return ans;
}
// @lc code=end

