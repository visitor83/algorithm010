/*
 * @lc app=leetcode.cn id=49 lang=c
 *
 * [49] 字母异位词分组
 */

// @lc code=start


#include <stdio.h>
#include <stdlib.h>
#include <uthash.h>

typedef struct tagEntry {
    char *same;
    struct tagEntry *next;
} Entry;

typedef struct {
    char *key;
    Entry head;
    int count;
    UT_hash_handle  hh;
} Map;

Map *g_map;
char ***g_ans;
int g_ansCnt;
int *g_colsSize;

void AddList(Map *ent, char *s)
{
    Entry *n;
    n = calloc(1, sizeof(Entry));
    n->same = s;
    n->next = ent->head.next;
    ent->head.next = n;
}

void GetResult()
{
    Map *ent, *tmp;
    Entry *p;
    int i;
    
    i = 0;
    HASH_ITER(hh, g_map, ent, tmp) {
        //printf("%s same cnt %d\n", ent->key, ent->count);
        g_ans[i] = calloc(ent->count, sizeof(char *));
        int j = 0;
        g_colsSize[i] = ent->count;
        p = &ent->head;
        while (p != NULL) {
            if (p->same) {
               g_ans[i][j++] = p->same;
               printf("   --> %s ", p->same);
            }
            p = p->next;
        }
        printf("\n");
        i++;
    }
}

int Sort(const void *p1, const void *p2)
{
  char a = *(char *)p1, b = *(char*)p2;
  return a > b ? 1 : -1;
}

char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes)
{
    int i;
    Map *ent, *newone;

    if (strs == NULL || strsSize == 0) {
      *returnSize = 0;
      return NULL;
    }

    g_map = NULL;
    g_ansCnt = 0;
    for (i = 0; i < strsSize; i++) {
        int nlen = strlen(strs[i]);
        char *ss = calloc(nlen + 1, sizeof(char));
        strcpy(ss, strs[i]);
        ss[nlen] = '\0';
        qsort(ss, nlen, sizeof(char), Sort);
        //printf("%d ss %s\n", i, ss);

        HASH_FIND_STR(g_map, ss, ent);
        if (ent) {
            AddList(ent, strs[i]);
            ++ent->count;
            free(ss);
        } else {
            newone = calloc(1, sizeof(Map));
            newone->key = ss;
            newone->count = 1;
            newone->head.same = strs[i];
            g_ansCnt++;

            HASH_ADD_STR(g_map, key, newone);
        }
    }
    printf("g_ansCnt %d\n", g_ansCnt);

    g_ans = (char ***)calloc(g_ansCnt, sizeof(char **));
    g_colsSize = calloc(g_ansCnt, sizeof(int));
    GetResult();

    *returnSize = g_ansCnt;
    *returnColumnSizes = g_colsSize;
 
    return g_ans;
}


// @lc code=end

