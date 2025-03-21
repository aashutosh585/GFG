//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


// } Driver Code Ends

class Solution {
  public:
    vector<int> dp;
    int helper(vector<int> &arr,int ind){
        if(ind<0) return 0;
        
        if(dp[ind]!=-1) return dp[ind];
        int way1 = arr[ind] + helper(arr,ind-2);
        int way2 = helper(arr,ind-1);
        
        
        return dp[ind] = max(way1,way2);
        
    }
    int findMaxSum(vector<int>& arr) {
        // code here
        
            int n =arr.size();
            dp.resize(n,-1);
            
            return helper(arr,n-1);
        
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.findMaxSum(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends