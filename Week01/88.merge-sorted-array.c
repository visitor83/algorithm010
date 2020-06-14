void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
  int i, j, k;

  if (!nums1 || !nums2) {
    return ;
  }

  k = m + n -1;
  i = m - 1;
  j = n - 1;
  while (i >= 0 || j >= 0) {
    if (i >= 0 && (j < 0 || nums1[i] > nums2[j])) {
      nums1[k] = nums1[i];
      i--;
      k--;
    }

    if (j >= 0 && (i < 0 || nums1[i] <= nums2[j])) {
      nums1[k] = nums2[j];
      j--;
      k--;
    }
  }
}