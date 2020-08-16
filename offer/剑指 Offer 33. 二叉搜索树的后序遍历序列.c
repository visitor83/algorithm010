
bool myfunc(int *arr, int lo, int hi) {
    int pviot, i, j;
    if (lo >= hi) {
        return true;
    }
    for (i = lo ; i < hi && arr[i] < arr[hi]; i++ ){
        ;
    }
    j = i;
    pviot = i;
    /*
    for (j = i; j < hi && arr[j] > arr[hi] ; j++) {
        ;
    }
    */
    for (j = i; j < hi; j++) { 
        if (arr[j] < arr[hi]) { 
            return false;
        }
    }

    //printf(" lo %d, hi %d <-> %d\n", lo, hi, pviot);
    //return j == hi && myfunc(arr, lo, pviot - 1) && myfunc(arr, pviot, hi - 1);
    return myfunc(arr, lo, pviot - 1) && myfunc(arr, pviot, hi - 1);
}


bool verifyPostorder(int* postorder, int postorderSize){
    if (!postorder || postorderSize <= 1) {
        return true;
    }
    return myfunc(postorder, 0, postorderSize - 1);
}