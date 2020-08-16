/*
 * @lc app=leetcode.cn id=389 lang=c
 *
 * [389] 找不同
 */

// @lc code=start
#define N  50

char findTheDifference(char * s, char * t){
    int t1[N] = {0}, t2[N] ={0};

    int i;

    for (i = 0; i < strlen(s); i++) {
        t1[s[i] - 'a']++;
    }

    for (i = 0; i < strlen(t); i++) {
        if (t1[t[i] - 'a'] > 0) {
            --t1[t[i] - 'a'];
        }  else {
            return t[i];
        }
        //t2[t[i] - 'a']++;
    }
    return ' ';
}

// @lc code=end

