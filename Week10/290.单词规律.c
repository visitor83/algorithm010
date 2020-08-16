/*
 * @lc app=leetcode.cn id=290 lang=c
 *
 * [290] 单词规律
 */

// @lc code=start

typedef struct {
    char *keystr;
    char relation;
    UT_hash_handle hh;
} Map;

#define N 1000
bool wordPattern(char * pattern, char * str){
    char *p;
    int j, slen = strlen(str);
    Map *ent, *c2s= NULL, *s2c = NULL;
    p = strtok(str, " ");
    j = 0;
    while (p) {
        if (j >  strlen(pattern)) {
            return false;
        }
        char *kstr = calloc(N, sizeof(char));
        memcpy(kstr, p, strlen(p) + 1);
        ent = NULL;

        HASH_FIND_STR(s2c, kstr, ent);
        if (!ent) {
            ent = calloc(1, sizeof(Map));
            ent->keystr = kstr;
            ent->relation = pattern[j];
            HASH_ADD_KEYPTR(hh, s2c, ent->keystr, strlen(ent->keystr), ent);
        } else {
            //printf("---> relation %c, pattern  %c\n", ent->relation, pattern[j]);
            if (ent->relation != pattern[j]) {
                return false;
            }
        }
        ent = NULL;
        int searchKey = (int) pattern[j];
        HASH_FIND_INT(c2s, &searchKey, ent);
        if (!ent) {
            ent = calloc(1, sizeof(Map));
            ent->relation = searchKey;
            ent->keystr = kstr;
            HASH_ADD_INT(c2s, relation, ent);
        } else {
            if (strcmp(ent->keystr, kstr) != 0) {
                return false;
            }
        }
        p = strtok(NULL, " ");
        j++;
    }
    if (j != strlen(pattern)) { 
        return false;
    }
    return true;
}
// @lc code=end

