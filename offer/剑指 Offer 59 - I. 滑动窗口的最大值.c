
int front, rear;
void PushTail(int * nums, int *sliding, int j, int k) {
    int data = nums[j];

    if (front == rear) {
        sliding[rear++] = j;
        return ;
    }

    if (j - k == sliding[front]) {
        sliding[front++];
    }
    while (front != rear && nums[ sliding[rear -1]] < data) {
        int popdata = nums[sliding[--rear]];
        //printf(" out : [%d] %d\n", end, popdata);
    }
    sliding[rear++] = j;
}

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    int *sliding;
    int i, j, cnt;
    int *ans = NULL;
    if (!nums || numsSize <= 0) {
        *returnSize = 0;
        return ans;
    }
    front = rear = 0;
    sliding = calloc(numsSize + 2, sizeof(int));
    ans = calloc(numsSize , sizeof(int));
    cnt = 0;
    for (j = 0; j < numsSize; j++) {
        if (j < k) {
            PushTail(nums, sliding, j, k);
            continue;
        }
        for (i = front ; i < rear; i++) {
            printf(" %d ", nums[sliding[i]]);
        }
        printf("\n");
        ans[cnt++] =  nums[sliding[front]];
        //break;
        PushTail(nums, sliding, j, k);
    }
    ans[cnt++] = nums[sliding[front]];
    *returnSize = cnt;
    return ans;
}