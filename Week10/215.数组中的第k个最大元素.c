/*
 * @lc app=leetcode.cn id=215 lang=c
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start


/*
在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

示例 1:

输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
示例 2:

输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4
说明:

你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。

 * 
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct HeapStruct *HeapQueueStru;
typedef int ElementType;

struct HeapStruct
{
    int Capacity;
    int Size;
    //ElementType Elements[20];
    ElementType *Elements;
};

HeapQueueStru Init(int max)
{
    HeapQueueStru heap;

    heap = malloc(sizeof(struct HeapStruct));
    heap->Capacity = max;
    heap->Size = 0;
    heap->Elements = (ElementType *)malloc(sizeof(ElementType) *max);

    memset(heap->Elements, 0, sizeof(ElementType) *max);
    heap->Elements[0] = 65535;
    return heap;
}

int Insert(ElementType val, HeapQueueStru heap)
{
    int i;

    if (heap->Size > heap->Capacity) {
        printf("Full\n");
        return -1;
    }

    for (i = ++heap->Size; heap->Elements[i/2] < val; i = i/2) {
        heap->Elements[i] = heap->Elements[i/2];
    }
    heap->Elements[i] = val;
    return 0;
}

ElementType Delete(HeapQueueStru heap)
{
    int i, child;
    ElementType max, last;

    max= heap->Elements[1];
    last = heap->Elements[heap->Size--];

    for (i = 1; i*2 <= heap->Size ; i = child) {
        child = i*2;
        if (child != heap->Size &&
                (heap->Elements[child] < heap->Elements[child +1])) {
            child++;
        }

        if (last < heap->Elements[child]) {
          heap->Elements[i] = heap->Elements[child];  
        } else {
            break;
        }
    }
    heap->Elements[i] = last;
    return max;
}


int findKthLargest(int* nums, int numsSize, int k)
{
    int i;

    HeapQueueStru heap =  Init(numsSize * 2);

    for (i = 0; i < numsSize; i++) {
        Insert(nums[i], heap);
    }


    //
    // pop min
    for (i = 1; i < k; i++) {
         Delete(heap);
    }


    //printf("\n%d\n", heap->Elements[1]);

    return heap->Elements[1];
}






// @lc code=end

