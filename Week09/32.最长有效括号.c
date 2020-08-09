/*
 * @lc app=leetcode.cn id=32 lang=c
 *
 * [32] 最长有效括号
 */

// @lc code=start
// 重复问题, 从尾部开始, 
// 输入: ")())())"
// ) 下一层碰 ( 返回 ，结果+1

int longestValidParentheses(char * s){
    int top, slen, ans = 0;
    int *stk;

    if (!s || strlen(s) <= 0) {
        return 0;
    }

    slen = strlen(s);
    stk = calloc(slen + 1, sizeof(int));
    for (int i = 0, top = 0; i < slen; i++) {
      if (s[i] == '(') {
          stk[top++] = i;
      } else if (s[i] == ')') {
        if (top != 0 && s[stk[top - 1]] == '(') {
          int pop = stk[--top];
          s[pop] = '*';
          s[i] = '*';
        }
      }
    }
    printf("%s\n", s);

    int cur = 0;
    for (int i = 0; i < slen ; i++) {
        if (s[i] == '*') {
            cur++;
            ans = fmax(cur, ans);
        } else {
            cur = 0;
        }
    }
    return ans;
}

// @lc code=end

