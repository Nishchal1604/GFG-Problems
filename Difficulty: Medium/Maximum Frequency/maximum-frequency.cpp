//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxFrequency(int arr[], int n, int k) {
        sort(arr, arr + n);
        
        long long sum = 0; // To keep track of the sum of the current window
        int maxFreq = 1;   // At least one element exists, so start with frequency 1
        int left = 0;      // Left pointer of the sliding window
        
        for (int right = 0; right < n; right++) {
            // Update the sum to include arr[right]
            sum += arr[right];
            
            // If the current window size times the right element's value 
            // exceeds the sum plus k, it means we can't convert all 
            // elements to arr[right] using k operations, so shrink the window
            while (arr[right] * (right - left + 1) > sum + k) {
                sum -= arr[left];
                left++;
            }
            
            // Update max frequency
            maxFreq = max(maxFreq, right - left + 1);
        }
        
        return maxFreq;
    
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t; // testcases
    while (t--) {
        int n, k;
        cin >> n >> k; // total size of array and integer k

        int arr[n];

        // inserting elements in the array
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution obj;
        // calling maxFrquency() function
        int ans = obj.maxFrequency(arr, n, k);

        cout << ans << endl;
    }
}
// } Driver Code Ends