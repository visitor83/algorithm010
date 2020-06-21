/**
 * Note: The returned array must be malloced, assume caller calls free().
 thanks to heapSort implement from https://www.geeksforgeeks.org/heap-sort/
 */

void Swap(int arr[], int i, int j)
{
    int t;
    t = arr[i]; arr[i] = arr[j]; arr[j] = t;
}
/* n   :the length of arr
 * idx :parent index 
*/
void HeapSort(int arr[], int n, int idx)
{
    int smallest = idx;
    int l, r;

    l = 2 * idx + 1;
    r = 2 * idx + 2;

    if (l < n && arr[l] < arr[smallest]) {
        smallest = l;
    }
    if (r < n && arr[r] < arr[smallest]) {
        smallest = r;
    }
    if (smallest != idx) {
        Swap(arr, smallest, idx);
        HeapSort(arr, n, smallest);
    }
}

int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize)
{
    int i, cnt;
    int *ans;

    if (k == 0 || arrSize <= 0) {
        ans = calloc(1, sizeof(int));
        *returnSize = 0;
        return ans;
    }
    
    ans = calloc(k, sizeof(int));
    /* find the last one of parent index*/
    for (i = arrSize/2 - 1; i >= 0; i--) {
        //printf("arr[%d] = %d, ", i, arr[i]);
        HeapSort(arr, arrSize, i);
    }

    cnt = 0;
    /* NOTE ! here, array doen't contain kth sort element ,
    extract the heap top element, must re-heapsort again
    */
    for (i = arrSize - 1; i >= 0 ; i--) {
        if (cnt < k) {
            ans[cnt++] = arr[0];
        }
        Swap(arr, 0, i);
        //printf("%d ", arr[0]);
        HeapSort(arr, i, 0);
    }
    //printf("\n");
    *returnSize = k;
    return ans;
}