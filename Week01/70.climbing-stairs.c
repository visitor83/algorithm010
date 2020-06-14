int climbStairs(int n)
{
	unsigned int *a;
    unsigned int f1, f2,i;

    if (n == 1 || n == 0) {
        return 1;
    }

    a = calloc(n+1, sizeof(unsigned int));
    a[0] = 1;
    a[1] = 2;

    for ( i = 2; i < n ; i++) {
       a[i] = a[i-1] + a[i-2];
    }
	
	return a[i-1];
}