//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    vector<vector<int>> dp;
    int helper(string &s,int i,int j){
        if(i>j) return 0;
        if(i==j){
            return s[i]==s[j];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j]){
            return dp[i][j] =  2 + helper(s,i+1,j-1);
        }
        else{
            return dp[i][j] = max(helper(s,i+1,j),helper(s,i,j-1));
        }
    }
    int longestPalinSubseq(string &s) {
        // code here
        
        int n = s.size();
        dp.resize(n,vector<int>(n,-1));
        return helper(s,0,s.size()-1);
    }
};


//{ Driver Code Starts.

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends