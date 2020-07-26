/*
 * @lc app=leetcode.cn id=208 lang=c
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start

#define     N 26
typedef struct  tagTrie{
    struct tagTire *child[N]; 
    bool isEnd;
} Trie;

/** Initialize your data structure here. */

Trie* trieCreate() {
    Trie *obj = calloc(1, sizeof(Trie));
    return obj;
}

/** Inserts a word into the trie. */
void trieInsert(Trie* obj, char * word) {
    Trie *t = obj;
    int i;
    if (!obj || strlen(word) <= 0) {
        return ;
    }
    for (i = 0; i < strlen(word); i++) {
        int d = word[i] - 'a';
        if (!t->child[d])  {
            t->child[d] = calloc(1, sizeof(Trie));
        } 
        t = (Trie *)t->child[d];
    }
    t->isEnd  = true;
}

/** Returns if the word is in the trie. */
bool trieSearch(Trie* obj, char * word) {
    Trie * t = obj;
    int i;
    for (i = 0; i < strlen(word); i++) {
        int d = word[i] - 'a';
        if (!t->child[d]) {
            return false;
        } else {
            t = (Trie*)t->child[d];
        }
    }

    return t->isEnd;
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool trieStartsWith(Trie* obj, char * prefix) {
    Trie * t = obj;
    int i;
    for (i = 0; i < strlen(prefix); i++) {
        int d = prefix[i] - 'a';
        if (!t->child[d]) {
            return false;
        } else {
            t = (Trie*)t->child[d];
        }
    }

    return true;
}

void trieFree(Trie* obj) {
    Trie *t = obj;
    if (!t) {
        return;
    }
    for (int i = 0; i < N; i++) {
        if (obj->child[i]) {
            trieFree(obj->child[i]);
            free(obj->child[i]);
        }
    }
}

