// Sterling Number 
/* number of ways that we can arrange r objects around indistinguishable circles 
	of length n, and every circle n must have at least one object around it*/
int s_recursive(int n,int k) {
    if (k == 1 || k == n) return 1;
    return s_recursive(n-1,k-1) + k*s_recursive(n-1,k);
}