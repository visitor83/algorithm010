int maxArea(int* height, int heightSize)
{
  int i, j, cur, ans;

  i = 0; 
  j = heightSize -1;
  if (!height || heightSize == 0) {
    return 0;
  }
  ans = 0;
  while (i < j) {
    cur = (j - i ) * fmin(height[i], height[j]);
    ans = fmax(cur, ans);

    if (height[j] > height[i]) {
      i++;
    } else {
      j--;
    }
  }
  return ans;
}