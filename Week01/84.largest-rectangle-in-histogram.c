int largestRectangleArea(int* heights, int heightsSize)
{
  int i, j, cur, top;
  int *stack;
  int *left, * right;
  int maxArea = 0;

  left  = calloc(heightsSize + 1, sizeof(int));
  right = calloc(heightsSize + 1, sizeof(int));
  stack = calloc(heightsSize + 1, sizeof(int));

  top = -1;
  for (i = 0; i < heightsSize; i++) {
    while (top != -1 && heights[stack[top]] >= heights[i]) {
      int pos = stack[top--];
    }
    left[i] = top == -1 ?  -1 : stack[top];
    stack[++top] = i;
  }

  memset(stack, 0, sizeof(int) * (heightsSize + 1));
  for (i = heightsSize - 1;  i >= 0; i--) {
    while (top != -1 && heights[stack[top]] >= heights[i]) {
      stack[top--];
    }
    right[i] = top == -1 ? heightsSize : stack[top];
    stack[++top] = i;
  }
  for (i = 0; i < heightsSize; i++) {
    //printf("%d ", right[i]);
    maxArea = fmax(maxArea, (right[i] - left[i] - 1) * heights[i]);
  }
  return maxArea;
}