/*
 * @lc app=leetcode.cn id=5 lang=c
 *
 * [5] 最长回文子串
 */

// @lc code=start

#define TRUE  (0)
#define FALSE (1)

int is_palin(char *s, int l, int r)
{
  while (l < r) {
    if (s[l] != s[r])  return FALSE;
    ++l; 
    --r;
  }
  return TRUE;
}

char * longestPalindrome(char * s){
  int l = strlen(s), i, j, m = 0; 
  char * a ;

  if (l == 0)  { return "";}
  if (l == 1)  { return s; }

  a = (char *) malloc(sizeof(char ) * (l + 1));
  memset(a, 0, sizeof(char) * (l + 1));

  //memcpy(a, s, 2);

  for ( i = 0; i < l ; ++ i) {
    for (j = i; j < l ; ++ j) {
      if (j - i + 1 > m   &&  (TRUE == is_palin (s, i, j))) {
        //printf("(%d, %d), m = %d, a = %s, diff=%d\n", i, j, m, a, j - i + 1);
        memcpy(a, s + i,  j - i + 1);
        
        a[j - i + 1] = '\0';
        m = j - i + 1;
      }
    }
  }

  //printf(" ans %d --> %s", m , a);
  return a;
}
// @lc code=end

