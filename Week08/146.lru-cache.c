/*
 * @lc app=leetcode.cn id=146 lang=c
 *
 * [146] LRU缓存机制
 */

// @lc code=start

typedef struct tagNode {
    int key, value;
    struct tagNode *prev, *next;
    UT_hash_handle hh;
} Node;

typedef struct tagLRUCache {
    Node *phash;
    Node *ptail, *phead;
    int count, cap;
} LRUCache;

LRUCache* lRUCacheCreate(int capacity) {
    LRUCache *obj = calloc(capacity + 1, sizeof(LRUCache));
    obj->phead = calloc(1, sizeof(Node));
    obj->ptail = obj->phead;
    obj->cap = capacity;
    return obj;
}

void RemoveHead(LRUCache *obj) {
    Node *ent = obj->phead->next;
    obj->phead->next = ent->next;
    if (ent->next != NULL) {
        ent->next->prev = obj->phead;
    }
    if (ent == obj->ptail) {
        obj->ptail = obj->phead;
    }
    HASH_DEL(obj->phash, ent); free(ent);
}

void AddTail(LRUCache *obj, Node *ent) {
    obj->ptail->next = ent;
    ent->prev = obj->ptail;
    obj->ptail = ent;
}

void MoveTail(LRUCache *obj, Node *ent) {
    if (ent != obj->ptail) {
        ent->prev->next = ent->next;
        ent->next->prev = ent->prev;
        AddTail(obj, ent);
        ent->next = NULL;
    }
}
void PrintList(LRUCache *obj) {
    Node *t = obj->phead->next;
    while (t != NULL) {
        printf("%d, ", t->value);
        t = t->next;
    }
    printf("\n");
}

int lRUCacheGet(LRUCache* obj, int key) {
    Node *ent = NULL;
    //PrintList(obj);
    HASH_FIND_INT(obj->phash, &key, ent);
    if (!ent) { return -1; }
    //printf("Get --> key %d\n", key);
    MoveTail(obj, ent);
    return ent->value;
}

void PrintHahs(LRUCache *obj) {
    Node *s, *tmp;
    HASH_ITER(hh, obj->phash, s, tmp) {
        if (s) { printf("(key %d, value %d), ", s->key, s->value);}
    }
    printf("\n");
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    Node *ent = NULL;
    if (!obj) { return ;}
    HASH_FIND_INT(obj->phash, &key, ent);
    if (ent) { //在则更新位置到末尾
        //ent = calloc(1, sizeof(Node));
        ent->value = value;
        MoveTail(obj, ent);
        return ;
    }
    if (obj->count >= obj->cap) {
        RemoveHead(obj);
        --obj->count;
    } 
    ent = calloc(1, sizeof(Node));
    ent->value = value; 
    ent->key = key;
    HASH_ADD_INT(obj->phash, key, ent);
    AddTail(obj, ent);
    ++obj->count;
    //PrintHahs(obj);
}

void lRUCacheFree(LRUCache* obj) {

}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 
 * lRUCachePut(obj, key, value);
 
 * lRUCacheFree(obj);
*/


