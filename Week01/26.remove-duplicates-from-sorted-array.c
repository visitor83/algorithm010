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