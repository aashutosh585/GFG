//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  const long long mod = 1e9 + 7;
    long long int fibo(int n, vector<long long int>&dp){
        if(n<=0) return 0;
        if(dp[n]!=-1) return dp[n];
        
        return dp[n]=fibo(n-1,dp)+fibo(n-2,dp)%mod;
    }
    
    long long int topDown(int n) {
        // code here
        vector<long long int>dp(n+1,-1);
        dp[1]=1,dp[2]=1;
        
        return fibo(n,dp)%mod;
    }
    
    long long int bottomUp(int n) {
        // code here
        if(n==0) return 0;
        if(n==1 || n==2) return 1;
        
        long long int a=0,b=1,c;
        
        for(int i=1;i<n;i++){
            c=a+b;
            a=b%mod;
            b=c%mod;
        }
        return c%mod;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    
cout << "~" << "\n";
}
}
// } Driver Code Ends