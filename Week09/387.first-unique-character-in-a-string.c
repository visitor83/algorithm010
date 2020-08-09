/*
 * @lc app=leetcode.cn id=387 lang=c
 *
 * [387] 字符串中的第一个唯一字符
 */

// @lc code=start

#define N 256

int firstUniqChar(char * s){
    const int INF = strlen(s) + 2;
    int map[N] = {0};

    for (int i = 0; i < strlen(s); i++) {
        map[s[i]]++;
    }
  
    for (int i = 0; i < strlen(s); i++) {
        if (map[s[i]] == 1) {
            return i;
        }
    }
   return -1;
   //return min;
}
// @lc code=end

