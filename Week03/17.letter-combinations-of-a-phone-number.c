/*
 * @lc app=leetcode.cn id=17 lang=c
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
/*
 * @lc app=leetcode.cn id=17 lang=c
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct tagNode {
    char *arr;
    struct tagNode *next;
} Node;

Node g_head;
Node *g_tail;
int g_ansCnt;

static char g_pad[10][4] = {
    "",
    "",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz",
};
static int g_padSize[10] ={0,0,3,3,3,3,3,4,3,4}; 

void AddNode (int *stk, int dep)
{
    Node *n = calloc(1, sizeof(Node));
    n->arr = calloc(dep + 1, sizeof(char));
    memcpy(n->arr, stk, dep * sizeof(char));
    g_tail->next = n;
    g_tail = n;
}

void LetterG(char *digits, char *stk, int dep, int slen)
{
    /* terminator */
    if (dep == slen) {
        //printf("end, stk %s\n", stk);
        AddNode(stk, dep);
        ++g_ansCnt;
        return ;
    }

    int pad= digits[dep] - '0';

    /* current level logic */
    for (int i = 0; i < g_padSize[pad]; i++) {
        stk[dep++] = g_pad[pad][i];
        /* drill down */
        LetterG(digits, stk, dep, slen);
        /* revert current level state */
        stk[--dep] = '\0';
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** letterCombinations(char * digits, int* returnSize)
{
    Node *p;
    char **ans;
    char *stk;
    int i, slen;

    slen = strlen(digits);
    if (slen == 0 || !digits) {
        *returnSize = 0;
        ans = calloc(1, sizeof(char*));
        ans[0] = calloc(1, sizeof(char));
        ans[0][0] = '\0';
        return ans;
    }
    g_head.next = NULL;
    g_tail = &g_head;
    g_ansCnt = 0;
    stk = calloc(slen, sizeof(char));

    LetterG(digits, stk,  0, slen);

    printf("g_anscnt = %d\n", g_ansCnt);
    i = 0;
    ans = calloc(g_ansCnt, sizeof(char *));
    p = g_head.next;
    while (p) {
        ans[i] = p->arr;
        i++;
        p = p->next;
    }
    free(stk);
    *returnSize = g_ansCnt;
    return ans;
}

// @lc code=end

