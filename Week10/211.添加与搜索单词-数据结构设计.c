/*
 * @lc app=leetcode.cn id=211 lang=c
 *
 * [211] 添加与搜索单词 - 数据结构设计
 */

// @lc code=start

#include <stdbool.h>
#define N 26
/* typedef struct tagTrie{
 * } Trie;
 */
typedef struct tagTrie {
    struct tagTrie *child[N];
    bool isEnd;
} WordDictionary;

/** Initialize your data structure here. */

WordDictionary* wordDictionaryCreate() {
    WordDictionary * obj = calloc(1, sizeof(WordDictionary));
    return obj;
}

/** Adds a word into the data structure. */
void wordDictionaryAddWord(WordDictionary* obj, char * word) {
    int i;
    WordDictionary *cur = obj;
    for (i = 0; i < strlen(word); i++) {
        int d = word[i] - 'a';
        if (!cur->child[d]) {
            cur->child[d] = calloc(1, sizeof(WordDictionary));
        }
        cur = cur->child[d];
    }
    cur->isEnd = true;
}

bool IsMatch(WordDictionary *cur, char *word, int pos) {
    int i, j;
    for (i = pos; i < strlen(word); ) {
        if (isalpha(word[i])) {
            int d = word[i] - 'a';
            if (cur->child[d]) {
                cur = cur->child[d];
            } else {
                return false;
            }
            i++;
        } else if (word[i] == '.') {
            for (j = 0; j < N; j++) {
                if (cur->child[j] && IsMatch(cur->child[j], word, i+1)) {
                    return true;
                }
            }
            return false;
        }
    }

    return cur->isEnd;
}

/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
bool wordDictionarySearch(WordDictionary* obj, char * word) {
    return IsMatch(obj, word, 0);
}

void wordDictionaryFree(WordDictionary* obj) {
    
}


// @lc code=end

