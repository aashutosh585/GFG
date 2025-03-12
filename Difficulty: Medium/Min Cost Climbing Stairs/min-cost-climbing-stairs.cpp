//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//Back-end complete function Template for C++

class Solution {
  public:
    int ways(int i,int n,vector<int>&arr,vector<int>&dp){
        if(i>=n) return 0;
        
        if(i==-1) return min(ways(i+1,n,arr,dp),ways(i+2,n,arr,dp));
        
        if(dp[i]!=-1) return dp[i];
        
        int p1=ways(i+1,n,arr,dp);
        int p2=ways(i+2,n,arr,dp);
        
        return dp[i]=arr[i]+min(p1,p2);
    }  
    int minCostClimbingStairs(vector<int>& cost) {
        // Write your code here
        vector<int>dp(cost.size(),-1);
        return ways(-1,cost.size(),cost,dp);
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution sln;
        int res = sln.minCostClimbingStairs(arr);
        cout << res << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends