
/* sliding记录字符对应的索引 */
int lengthOfLongestSubstring2(char* s){
    int sliding[256] = {0}, slen;
    int j, i, minLen;

    slen = strlen(s);
    if (!s || slen <= 0) { return 0;}
    if (slen == 1) { return 1;}
    
    minLen = 0;
    memset(sliding, -1, sizeof(int) * 256);

    for (i = 0, j = 0; j < slen && i < slen; ) {
        if (sliding[s[j]] != -1) {
            minLen = fmax(minLen, j - i);
            //i = sliding[s[j]] + 1;
            while (i < sliding[s[j]] + 1) {
                sliding[s[i]] = -1; i++;
            }
        }
        sliding[s[j]] = j;
        j++;
    }
    minLen  = fmax(minLen, j - i);
    return minLen;
}

// hash (key 字符值， value = 字符位置)
int lengthOfLongestSubstring(char * s){
    int map[280] = {0}, i, j;
    int ans = 0;
    if (!s) {
        return 0;
    }

    for (i = 0, j = 0; j < strlen(s); j++) {
        if (map[s[j]]) {
            //ans = fmax(ans, j - i);
            //printf("ans %d (%d, %d)\n", ans, i, j);
            i = fmax(map[s[j]], i) ;
        } 
        map[s[j]] = j + 1;
        ans = fmax(ans, j- i + 1);
    }
    return ans;
}