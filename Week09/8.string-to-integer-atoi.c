/*
 * @lc app=leetcode.cn id=8 lang=c
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start


int myAtoi(char * str){
    int i, slen;
    long res = 0;
    int sign = 1;

    slen = strlen(str);
    while (i < slen && isspace(str[i])) {
        i++;
    }
    if (i >= slen) {
        return 0;
    }

    if ((!isdigit(str[i]) && (str[i] != '-' && str[i] != '+'))) {
        return 0;
    }
    if (str[i] == '-' || str[i] == '+') { 
        sign = (str[i] == '-') ? -1 : 1; 
        i++; 
    }
    //printf(" sign %d, i %d\n", sign, i);
    res = 0;
    for ( ; i < slen; i++) {
        if (isdigit(str[i])) {
            res = res * 10 + str[i] - '0';
            if (res * sign < INT_MIN) { return INT_MIN; }
            if (res * sign > INT_MAX) { return INT_MAX; }
        } else {
            break;
        }
    }

    return res * sign ; 
}

// @lc code=end

