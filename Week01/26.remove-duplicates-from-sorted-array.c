void Swap(int *nums, int i, int j)
{
  int t;
  t = nums[i];
  nums[i] = nums[j];
  nums[j] = t;
}

int removeDuplicates(int* nums, int numsSize)
{
  int i, j, ansLength;

  if (numsSize <= 1) {
    return numsSize;
  }

  ansLength = 1;
  i = 0;
  j = 0;
  while (j < numsSize) {
    if (j &&  nums[i] != nums[j]) {
      Swap(nums, i + 1, j);
      ++i;
      ++ansLength;
    }
    j++;
  }
  return ansLength;
}
/* @ 2020/07/07  */
int removeDuplicates(int* nums, int numsSize)
{
    int i, j;
    
    if (numsSize == 0) {
        return 0;
    }

    i = 0;
    j = 1;
    while (j < numsSize) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
        j++;
    }
    return  i + 1;
}