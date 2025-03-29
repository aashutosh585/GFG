//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // vector<vector<int>>dp;
    int solve(int idx,int jdx,vector<vector<int>>& arr, vector<vector<int>>&dp){
        
        int n=arr.size();
        
        if(idx==n) return 0;
        if(dp[idx][jdx]!=-1) return dp[idx][jdx];
        
        // int x=0,y=0;
        // if(jdx==0){
        //     x=arr[idx][1]+solve(idx+1,1,arr,dp);
        //     y=arr[idx][2]+solve(idx+1,2,arr,dp);
            
        // }
        // else if(idx==1){
        //     x=arr[idx][0]+solve(idx+1,0,arr,dp);
        //     y=arr[idx][2]+solve(idx+1,2,arr,dp);
        // }
        // else{
        //     x=arr[idx][0]+solve(idx+1,0,arr,dp);
        //     y=arr[idx][1]+solve(idx+1,1,arr,dp);
        // }
        
        int ans=0;
        for(int i=0;i<3;i++){
            if(i==jdx) continue;
            int x=arr[idx][i]+solve(idx+1,i,arr,dp);
            ans=max(ans,x);
        }
        return dp[idx][jdx]=ans;
        
    }
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int n=arr.size(),ans=0;
        vector<vector<int>>dp(n,vector<int>(3,-1)); 
        
        for(int i=0;i<3;i++){
            // cout<<ans<<endl;
            int x=arr[0][i]+solve(1,i,arr,dp);
            ans=max(ans,x);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends