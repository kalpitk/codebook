// Segment Tree
int tree[MAX] = {0};  // To store segment tree 
int lazy[MAX] = {0};  // To store pending updates  
/*  si -> index of current node in segment tree 
    ss and se -> Starting and ending indexes of elements for 
                 which current nodes stores sum. 
    us and ue -> starting and ending indexes of update query 
    diff -> which we need to add in the range us to ue */
void updateRangeUtil(int si, int ss, int se, int us, 
                     int ue, int diff) { 
    // If lazy value is non-zero for current node of segment 
    // tree, then there are some pending updates. So we need 
    // to make sure that the pending updates are done before 
    // making new updates. Because this value may be used by 
    // parent after recursive calls (See last line of this 
    // function) 
    if (lazy[si] != 0) { 
        // Make pending updates using value stored
        // in lazy nodes 
        tree[si] += (se-ss+1)*lazy[si]; 
  
        // checking if it is not leaf node because if 
        // it is leaf node then we cannot go further 
        if (ss != se) { 
            lazy[si*2 + 1]   += lazy[si]; 
            lazy[si*2 + 2]   += lazy[si]; 
        } 
        lazy[si] = 0; 
    } 
  
    // out of range 
    if (ss>se || ss>ue || se<us) 
        return ; 
  
    // Current segment is fully in range 
    if (ss>=us && se<=ue) 
    { 
        // Add the difference to current node 
        tree[si] += (se-ss+1)*diff; 
  
        // same logic for checking leaf node or not 
        if (ss != se) 
        { 
            // This is where we store values in lazy nodes, 
            // rather than updating the segment tree itelf 
            // Since we don't need these updated values now 
            // we postpone updates by storing values in lazy[] 
            lazy[si*2 + 1]   += diff; 
            lazy[si*2 + 2]   += diff; 
        } 
        return; 
    } 
  
    // If not completely in rang, but overlaps, recur for 
    // children, 
    int mid = (ss+se)/2; 
    updateRangeUtil(si*2+1, ss, mid, us, ue, diff); 
    updateRangeUtil(si*2+2, mid+1, se, us, ue, diff); 
  
    // And use the result of children calls to update this 
    // node 
    tree[si] = tree[si*2+1] + tree[si*2+2]; 
} 
  
// Update function
/*  us and eu -> starting and ending indexes of update query 
    ue  -> ending index of update query 
    diff -> which we need to add in the range us to ue */
void updateRange(int n, int us, int ue, int diff) 
{ 
   updateRangeUtil(0, 0, n-1, us, ue, diff); 
} 
  
  
/*  Query function
    si --> Index of current node in the segment tree. 
           Initially 0 is passed as root is always at' 
           index 0 
    ss & se  --> Starting and ending indexes of the 
                 segment represented by current node, 
                 i.e., tree[si] 
    qs & qe  --> Starting and ending indexes of query 
                 range */
int getSumUtil(int ss, int se, int qs, int qe, int si) 
{ 
    if (lazy[si] != 0) 
    { 
        tree[si] += (se-ss+1)*lazy[si]; 
        if (ss != se) {
            lazy[si*2+1] += lazy[si]; 
            lazy[si*2+2] += lazy[si]; 
        }
        lazy[si] = 0; 
    } 
  
    if (ss>se||ss>qe||se<qs)return 0; 
  
    if (ss>=qs && se<=qe) return tree[si]; 
  
    int mid = (ss + se)/2; 
    return getSumUtil(ss, mid, qs, qe, 2*si+1) + 
           getSumUtil(mid+1, se, qs, qe, 2*si+2); 
} 
  