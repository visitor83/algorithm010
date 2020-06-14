typedef struct {
  int key;
  int pos;
  int cnt;
  UT_hash_handle hh;
} Map;

Map *gp_hashHdl;
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
  int i, cur, ansCnt;
  int *ans;
  Map *ent;

  gp_hashHdl = NULL;
  ans = calloc(10, sizeof(int));
  ansCnt = 0;

  for (i = 0; i < numsSize; i++) {
    ent = NULL;
    cur = target - nums[i];
    HASH_FIND_INT(gp_hashHdl, &cur, ent);
    if (ent && ent->cnt) {
      ans[ansCnt++] = ent->pos;
      ans[ansCnt++] = i;
      --ent->cnt;
    } 
    /* keep in mind that insert hash table is the nofound nums[i] */
    HASH_FIND_INT(gp_hashHdl, &nums[i], ent);
    if (!ent) {
      ent = calloc(1, sizeof(Map));
      ent->key = nums[i];
      ent->pos = i;
      ent->cnt = 1;
      HASH_ADD_INT(gp_hashHdl, key, ent);
    }
  }
  *returnSize = ansCnt;
  return ans;
}