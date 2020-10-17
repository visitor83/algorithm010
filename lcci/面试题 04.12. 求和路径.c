
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define N    20
typedef struct tagMap {
    int data;
    struct TreeNode * tnode;
    int occur;
    UT_hash_handle hh;
} Map;
Map *g_map;
int  myfunc(struct TreeNode *cur, int target, int sum) {
    // terminal
    if (!cur) {
        return 0;
    }
    Map *el = NULL;
    int findVal, totalCount = 0;

    sum = sum + cur->val;
    //printf (" %d, ", sum);
    findVal = sum - target; el = NULL; 
    HASH_FIND_INT(g_map, &findVal, el);
    if (el) {
        //printf("---$$ %d, %d d=%d, el-path=%d\n", findVal, *ans, d, el->path);
        //g_ans += el->occur;
        totalCount += el->occur;
    }
    if(sum == target) { 
        //(*ans)++;  g_ans++;
        totalCount++;
    }
    // current logic
    el = NULL;
    HASH_FIND_INT(g_map, &sum, el);
    if (el) {
        el->occur++;
    } else {
        el = calloc(1, sizeof(Map));
        el->data = sum;  HASH_ADD_INT(g_map, data, el);
        el->occur = 1;
    }
  
    totalCount += myfunc(cur->left, target , sum);
    // drill down
    totalCount +=  myfunc(cur->right, target, sum);
    // revert state
    if ((--el->occur) == 0) {
        HASH_DEL(g_map, el);
    }
    sum -= cur->val;
    return totalCount;
}

int pathSum(struct TreeNode* root, int sum) {
    g_map = NULL;
    // 不需要置0， 查找时 sum == target , 则++
    //HASH_ADD_INT(g_map, data, el);
    return myfunc(root, sum, 0);
}