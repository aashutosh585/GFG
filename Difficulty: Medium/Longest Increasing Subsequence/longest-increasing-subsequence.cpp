//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    
    int maxLen(int i,int n,vector<int>&arr,vector<int>&dp){
        if(dp[i]!=-1) return dp[i];
        
        int cnt=1;
        for(int j=i+1;j<n;j++){
            if(arr[i]<arr[j]){
               cnt=max(cnt,1+maxLen(j,n,arr,dp));
            }
        }
        dp[i]=cnt;
        return dp[i];
      
    }
    
    int lis(vector<int>& arr) {
        // code here
        int n=arr.size(),ans=0;
        vector<int>dp(n,-1);
        
        for(int i=0;i<n;i++){
            ans= max(ans,maxLen(i,n,arr,dp));
        }
       
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--) {
        int n;
        vector<int> arr;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.lis(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends