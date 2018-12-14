// Prints smaller elements on left side of every element 
void printPrevSmaller(int arr[], int n) { 
    stack<int> S; 
    // Traverse all array elements 
    for (int i=0; i<n; i++) { 
        // Keep removing top element from S while the top 
        // element is greater than or equal to arr[i] 
        while (!S.empty() && S.top() >= arr[i]) S.pop(); 
        cout << S.top() << ", ";
        S.push(arr[i]); 
    } 
} 
