//{ Driver Code Starts
#include <bits/stdc++.h>
#include <limits.h>
#include <random>
#include <sstream>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> minAnd2ndMin(vector<int> &arr) {
        
        int n = arr.size();
        int smallest= arr[0];
        int ssmallest= INT_MAX;
        
        for(int i=1; i<n; i++){
            if(arr[i]<smallest){
                ssmallest= smallest;
                smallest= arr[i];
            }
            else if(arr[i]>smallest && arr[i]< ssmallest){
                ssmallest= arr[i];
            }
        }
        
        if (ssmallest == INT_MAX) return {-1}; // No valid second smallest found
        return {smallest, ssmallest};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        vector<int> ans = ob.minAnd2ndMin(arr);
        if (ans[0] == -1)
            cout << -1 << endl;
        else
            cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}
// } Driver Code Ends