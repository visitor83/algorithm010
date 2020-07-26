/*
 * @lc app=leetcode.cn id=433 lang=c
 *
 * [433] 最小基因变化
 */

// @lc code=start


#define SEQ_SIZE    8
typedef struct tagMap {
    //char arr[SEQ_SIZE];
    char *arr;
    int idx;
    bool vis;
    UT_hash_handle hh;
} Map;

Map *g_map;
int g_ans;
bool g_found = false;

int GetDiff(char *a, char *b)
{
    int dist = 0;
    for (int i = 0; i < SEQ_SIZE; i++) {
        if (a[i] != b[i]) {
            dist++;
        }
    }
    return dist;
}

void D(char *start, char *end, char *next, int step)
{
    Map *iter, *tmp;
    /*terminator */
    if (!strcmp(next, end)) {
        g_ans = fmin(step, g_ans);
        g_found = true;
        return ; 
    }

    if (g_found &&  step > g_ans) {
        return ;
    }

    HASH_ITER(hh, g_map, iter, tmp) {
        if (iter) {
            int diff = GetDiff(iter->arr, next);
            if (diff == 1 && !(iter->vis)) {
                /* drill down */
                iter->vis = true;
                D(start, end, iter->arr, step + 1);
                /* revert state ??*/
                iter->vis = false;
            }
        }
    }
}

int minMutation(char * start, char * end, char ** bank, int bankSize)
{
    Map * tmp = NULL, *iter = NULL;

    g_map = NULL;
    g_ans = INT_MAX;
    g_found = false;

    if (!start || !end || bankSize <= 0) {
        return -1;
    }
    // build bank in hashmap

    for (int i = 0; i < bankSize; i++) {
        Map *m = calloc(1, sizeof(Map)) ;
        m->arr = bank[i];
        m->vis = false;
        HASH_ADD_STR(g_map, arr, m);
    }

    HASH_ITER(hh, g_map, iter, tmp) {
        if (iter) {
            printf("%s\n", iter->arr);
        }
    }

    HASH_FIND_STR(g_map, end, tmp);
    if (!tmp) {
        printf("end not foud in map\n");
        return -1;
    }

    D(start, end, start, 0);

    return (g_found == true)  ? g_ans : -1;
}
// @lc code=end

