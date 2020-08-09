/*
 * @lc app=leetcode.cn id=151 lang=c
 *
 * [151] 翻转字符串里的单词
 */

// @lc code=start


int slen;
void Swap(char *s, int lo, int hi) {
    int i,j;
    char chaf;
    for (i = lo, j = hi; i <= j; i++, j--) {
        chaf = s[i]; s[i] = s[j]; s[j] = chaf;
    }  
}
int dep;
char *ReWord(char *s, int start)
{
    int j, cnt;

    if (start >= slen) {
         printf("start %d, slen %d\n", start, slen);
        return s;
    }
    cnt = 0;
    for (j = start; j < slen; j++) {
        if (!isspace(s[j])) {  
            cnt++; 
        }
        if ( j == slen - 1 || (isspace(s[j+1]) && !isspace(s[j]))) {
            //printf("---> %d\n", j);
            break;
        }
    }

    dep++;
    Swap(s, start, j);  
/*
    if (!cnt) {
        printf("dep %s\n", s);
        if (start - 1>= 0 && isspace(s[start - 1])) {
            printf ("xxxx\n");
            s[start - 1] = '\0';
        }
        return s;
    }
    */
    // add space
    int next = start + cnt;
    if (next < slen) { 
        s[next] = ' '; next++;
    }

    //printf("(%d, [%d %d]) next %d cnt %d\n", dep, start, j, next, cnt);
    //printf(" [%d] %s\n", dep, s);
    return ReWord(s, next);
}

char * reverseWords(char * s){
    int j;
    slen = strlen(s); dep = 0;
    if (slen <= 0) {
        return s;
    }
    Swap(s, 0, slen - 1);
    //printf("%s\n", s);
    char  * ans =  ReWord(s, 0);
    j = slen - 1;  
    while (j >= 0 && isspace(s[j])) {
        j--;
    }
    ans[j+1] = '\0'; 
    return ans;
}
// @lc code=end

