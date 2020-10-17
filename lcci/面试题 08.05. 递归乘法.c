
int myfunc(int smaller, int bigger) {
    // terminator
    if (smaller == 0) {
        return 0;
    } else if (smaller == 1) {
        return bigger;
    }
    
    int s = smaller >> 1;
    int lson, rson;
    lson = myfunc(s, bigger);
    rson = lson;
    if (smaller & 1) {
        //rson = myfunc(smaller - s, bigger);
        rson = lson + bigger;
    }
    return lson + rson;
}

int multiply(int A, int B){
    int bigger, smaller;

    bigger = A  > B ? A : B;
    smaller = A > B ? B : A;
    return myfunc(smaller, bigger);
}