/*
 * @lc app=leetcode.cn id=242 lang=c
 *
 * [242] 有效的字母异位词
 */

// @lc code=start

#define MAX_SIZE   256

bool isAnagram(char * s, char * t)
{
  int i;
  int map[MAX_SIZE] = {0};

  if (strlen(s) != strlen(t)) {
    return false;
  }

  for (i = 0; s[i] != '\0'; i++) {
    map[s[i]]++;
    map[t[i]]--;
  }

  for (i = 0; i < MAX_SIZE; i++) {
    if (map[i] != 0) {
      return false;
    }
  }

  return true;
}


// @lc code=end

