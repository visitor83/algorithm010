#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


typedef struct {
    int *arr;
    int front;
    int rear;
    int size; 
    int cap;
} MyCircularDeque;

bool myCircularDequeIsFull(MyCircularDeque* obj) ;
bool myCircularDequeIsEmpty(MyCircularDeque* obj) ;
/** Initialize your data structure here. Set the size of the deque to be k. */

MyCircularDeque* myCircularDequeCreate(int k) 
{ 
    MyCircularDeque *obj = calloc(1, sizeof(MyCircularDeque));
    obj->arr = calloc(k+1, sizeof(int));
    obj->cap= k+1;
    obj->size = 0;
    obj->front = 0;
    obj->rear = 0;
    return obj;
}

/** Adds an item at the front of Deque. Return true if the operation is successful. */
bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) 
{
    int pos;
    if (!obj || myCircularDequeIsFull(obj)) {
        return false;
    }

    pos = (obj->front + obj->cap - 1) % obj->cap;
    obj->arr[pos] = value;
    obj->front = pos;
    return true;
}

/** Adds an item at the rear of Deque. Return true if the operation is successful. */
bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) 
{
    if (!obj || myCircularDequeIsFull(obj)) {
        return false; 
    }

    obj->arr[obj->rear] = value;
    obj->rear = (obj->rear + 1) % obj->cap;
    return true;
}

/** Deletes an item from the front of Deque. Return true if the operation is successful. */
bool myCircularDequeDeleteFront(MyCircularDeque* obj) 
{
    int pos;
    if (!obj || myCircularDequeIsEmpty(obj)) {
        return false;
    }
    pos = (obj->front + 1) % obj->cap;
    obj->front = pos;
    return true;
}

/** Deletes an item from the rear of Deque. Return true if the operation is successful. */
bool myCircularDequeDeleteLast(MyCircularDeque* obj) 
{
    int pos;

    if (myCircularDequeIsEmpty(obj)) {
        return false;
    }
    // NOTE!
    pos = (obj->rear + obj->cap - 1) % obj->cap;
    obj->rear = pos;
    return true;
}

/** Get the front item from the deque. */
int myCircularDequeGetFront(MyCircularDeque* obj) 
{
    if (myCircularDequeIsEmpty(obj)) {
        return -1;
    }
    return obj->arr[obj->front];
}

/** Get the last item from the deque. */
int myCircularDequeGetRear(MyCircularDeque* obj) 
{
    if (myCircularDequeIsEmpty(obj)) {
        return -1;
    }
    // NOTE!
    int pos = (obj->rear + obj->cap - 1) % obj->cap;
    return obj->arr[pos];
}

/** Checks whether the circular deque is empty or not. */
bool myCircularDequeIsEmpty(MyCircularDeque* obj) 
{
    return (obj->front == obj->rear) ? true : false;
}

/** Checks whether the circular deque is full or not. */
bool myCircularDequeIsFull(MyCircularDeque* obj) 
{  
    return ((obj->rear + 1) % obj->cap) == obj->front ? true : false;
}

void myCircularDequeFree(MyCircularDeque* obj) 
{
    
}

/**
 * Your MyCircularDeque struct will be instantiated and called as such:
 * MyCircularDeque* obj = myCircularDequeCreate(k);
 * bool param_1 = myCircularDequeInsertFront(obj, value);
 
 * bool param_2 = myCircularDequeInsertLast(obj, value);
 
 * bool param_3 = myCircularDequeDeleteFront(obj);
 
 * bool param_4 = myCircularDequeDeleteLast(obj);
 
 * int param_5 = myCircularDequeGetFront(obj);
 
 * int param_6 = myCircularDequeGetRear(obj);
 
 * bool param_7 = myCircularDequeIsEmpty(obj);
 
 * bool param_8 = myCircularDequeIsFull(obj);
 
 * myCircularDequeFree(obj);
*/