bool compare(Query x, Query y)
    if (x.L/block != y.L/block) 
        return x.L/block < y.L/block; 
    return x.R < y.R; 
  
void queryResults(int a[], int n, Query q[], int m) 
    sort(q, q + m, compare); 
  
    int currL = 0, currR = 0; 
    int currSum = 0; 
  
    for (int i=0; i<m; i++) 
        int L = q[i].L, R = q[i].R; 

        while (currL < L) 
            currSum -= a[currL]; 
            currL++;
  
        while (currL > L)
            currSum += a[currL-1]; 
            currL--; 

        while (currR <= R)
            currSum += a[currR]; 
            currR++; 
  
        while (currR > R+1) 
            currSum -= a[currR-1]; 
            currR--; 
