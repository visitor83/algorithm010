/*
 * @lc app=leetcode.cn id=20 lang=c
 *
 * [20] 有效的括号
 */

// @lc code=start


bool isValid(char * s){
    int *stk, top;
    int slen, i;

    top = 0;
    slen = strlen(s);
    stk = calloc( slen, sizeof(int));

    i = 0;
    while ( i < slen) {
        if (s[i] == '(') { stk[top++] = ')'; }
        else if (s[i] == '{') { stk[top++] = '}';}
        else if (s[i] == '[') { stk[top++] = ']';}
        else if (top == 0 || stk[--top] != s[i]) {
            return false;
        } 
        i++;
    }
    return top == 0 ? true : false;
}

// @lc code=end

