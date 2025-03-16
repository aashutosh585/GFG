//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
   int solve(vector<int>&arr,int i,vector<int>&dp){
      if(i >= arr.size()-1)
       return 0;
       
       if(dp[i] != -1)
        return dp[i];
      int ans = INT_MAX;
      for(int j = i+1; j <= i+arr[i];++j){
          int res = solve(arr,j,dp);
          if(res != INT_MAX)
           ans = min(ans,res+1);
      }
      return dp[i] = ans;
  }
    int minJumps(vector<int>& arr) {
        // code here
       //recursive approach
       vector<int>dp(arr.size()+1,-1);
        int ans = solve(arr,0,dp);
        if(ans == INT_MAX)
         return -1;
        return ans;
    }

};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends