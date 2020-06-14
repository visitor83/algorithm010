void rotate(int* nums, int numsSize, int k){
  int j = k, move;
  int l = numsSize - 1, t;
  
  while (j > 0) {
    move = nums[l];
    for (int i = 0; i < numsSize ; i++) {
      t = nums[i];
      nums[i] = move;
      move = t;
    }
    --j;
  }
}