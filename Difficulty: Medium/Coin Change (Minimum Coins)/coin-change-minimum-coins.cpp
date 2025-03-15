//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int helper(int idx,vector<int> &coins, int sum, vector<vector<int>> &dp)
    {
        if(sum == 0)
            return 0;
        if(idx >= coins.size())
            return INT_MAX;
        if( dp[idx][sum] != -1 )
            return dp[idx][sum];
            
        int ans = helper(idx+1,coins,sum,dp);
   
        if(coins[idx] <= sum)
        {
                int temp = helper(idx,coins,sum-coins[idx],dp);
                if(temp != INT_MAX)
                    temp = 1+temp;
                ans = min(ans,temp);
        }
        return dp[idx][sum]=ans;
        
    }
    int minCoins(vector<int> &coins, int sum) {
        // code here
        vector<vector<int>> dp(coins.size() +1,vector<int>(sum+1,-1));
        int ans = helper(0,coins,sum,dp);
        if(ans == INT_MAX)
            return -1;
        else 
            return ans;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minCoins(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends