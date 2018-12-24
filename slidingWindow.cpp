// Sliding Window - Deque -O(n) 
// window size - k
void printKMax(int arr[], int n, int k) { 
    std::deque<int>  Qi(k); 

    int i; 
    for (i = 0; i < k; ++i) { 
        // For very element, the previous smaller elements are useless so 
        // remove them from Qi 
        while ( (!Qi.empty()) && arr[i] >= arr[Qi.back()]) Qi.pop_back();
        Qi.push_back(i); 
    } 
  
    // Process rest of the elements, i.e., from arr[k] to arr[n-1] 
    for ( ; i < n; ++i) { 
        // The element at the front of the queue is the largest element of 
        // previous window, so print it 
        cout << arr[Qi.front()] << " "; 
  
        // Remove the elements which are out of this window 
        while ( (!Qi.empty()) && Qi.front() <= i - k) 
            Qi.pop_front();  // Remove from front of queue 
  
        // Remove all elements smaller than the currently 
        // being added element (remove useless elements) 
        while ( (!Qi.empty()) && arr[i] >= arr[Qi.back()]) Qi.pop_back(); 
        Qi.push_back(i); 
    } 
    cout << arr[Qi.front()]; 
} 