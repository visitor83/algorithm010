/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize)
{
  int j, m, carry, k;
  int *ans;

  ans = calloc(digitsSize + 1, sizeof(int));

  if (digitsSize == 0 || !digits) {
    *returnSize = 1;
    ans[0]++;
    return ans;
  }

  k = digitsSize;
  j = digitsSize;
  carry = 0;
  while (j-- > 0) {
    if (j == digitsSize - 1) {
      m = digits[j] + 1;
    } else {
      m = digits[j] + carry;
      carry = 0;
    }
    carry = m / 10;
    ans[j] = m % 10;
  }

  if (carry != 0) {
    memmove(ans, ans+1, sizeof(int) * digitsSize);
    ans[0] = carry;
    k++;
  }
  *returnSize = k;
  return ans;
}