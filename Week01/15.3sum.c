#define  COL_SIZE  3

typedef struct tagNode {
  int ans[COL_SIZE];
  struct tagNode *next;
} Node;

int **g_ans;
int g_ansCnt;
Node g_head;

void SaveResult(int *nums, int k, int lo, int hi)
{
  int i;
  Node *n;

  i = 0;
  n = calloc(1, sizeof(Node));
  n->ans[i++] = nums[k];
  n->ans[i++] = nums[lo];
  n->ans[i++] = nums[hi];

  n->next = g_head.next;
  g_head.next = n;
}

int Sort(const void *p1, const void *p2)
{
  int a = *(int *)p1;
  int b = *(int *)p2;
  return a > b ? 1 : -1;
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
  int i, j, k, sum;
  int **ans;
  Node *iter;
  int *colSize;

  qsort(nums, numsSize, sizeof(int), Sort);

  g_head.next = NULL;
  g_ansCnt = 0;
  k = 0;
  while (numsSize >= COL_SIZE &&  k < numsSize - 2) {
    i = k + 1;
    j = numsSize - 1;

    if (k != 0 && nums[k] == nums[k-1]) {
      k++;
      continue;
    }

    while (i < j) { 
      sum = nums[k] + nums[i] + nums[j];
      if (sum == 0) {
        /*printf("%d %d %d\n", nums[k], nums[i], nums[j]);*/
        SaveResult(nums, k, i, j);
        ++g_ansCnt;
         
        while (i < j && nums[i] == nums[++i]) {
          ;
        }
        while (i < j && nums[j] == nums[--j]) {
          ;
        }
      } else if (sum < 0) {
        ++i;
      } else if (sum > 0){
        --j;
      }
    }
    k++;
  }

  /*printf("g_ansCnt %d\n", g_ansCnt);*/
  ans = calloc(g_ansCnt, sizeof(int *));
  colSize = calloc(g_ansCnt, sizeof(int));
  iter = g_head.next;
  i = 0;
  while (iter) {
    ans[i] = &iter->ans[0];
    colSize[i] = COL_SIZE;
    iter = iter->next;
    i++;
  }

  *returnSize = g_ansCnt;
  *returnColumnSizes = colSize;
  return ans;
}