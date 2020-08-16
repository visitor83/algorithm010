
int g_slen;
// 类似爬楼梯问题， i 位置要没从i-1, 或者i-2来
int myfunc(char *s, int j) {
    int res;
    // terminator
    if (j >= g_slen) {
        return 1;
    }

    res = myfunc(s, j + 1);    
    if (j + 1 < g_slen && (s[j] == '1' || (s[j] == '2' && s[j+1] <= '5'))) {
        res += myfunc(s, j+2);
    }
    return res;
}

int translateNum(int num){
    char s[64] = {0};
    sprintf(s, "%d", num);
    g_slen = strlen(s);
    //printf("%s len %d\n", s, strlen(s));
    return myfunc(s, 0);
}