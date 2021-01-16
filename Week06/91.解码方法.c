/*
 * @lc app=leetcode.cn id=91 lang=c
 *
 * [91] 解码方法
 */

// @lc code=start


int slen;
int myfunc(char *s, int j) {
    int res = 0;
    // 终止条件是啥？？
    if (j == slen)  { 
        return 1; 
    }

    // 死胡同不走了
    if (s[j] == '0') { 
        return 0;
    }

    res = myfunc(s, j+1);
    //if ( j+1 <slen && (s[j] == '1' || s[j] ==  '2')  && (s[j+1] >= '0' && s[j+1] <= '6')) {
    if ( j+1 <slen && (s[j] == '1' || (s[j] ==  '2' && s[j+1] <= '6'))) {
        res += myfunc(s, j+2) ;
   }
    //printf("res %d\n", res);
    return res;
}

int numDecodings(char * s){
    if (!s) {
        return 0;
    }
    slen = strlen(s);
    return myfunc(s, 0);
}

// @lc code=end

