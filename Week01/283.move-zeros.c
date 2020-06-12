void Swap(int *nums, int i, int j)
{
  int t;
  t = nums[i]; 
  nums[i] = nums[j];
  nums[j] = t;
}

void moveZeroes(int* nums, int numsSize)
{ 
  int i, j;

  i = 0; 
  j = 0;

  while (j < numsSize) {
    if (nums[j] != 0) {
      Swap(nums, i, j);
      i++;
    }
    j++;
  }

}