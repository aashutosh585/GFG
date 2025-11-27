class Solution {
  public:
    vector<vector<int>>dp;
    int solve(int i,int j, vector<int>&arr){
        if(i==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int res=1e9;
        
        for(int k=i;k<j;k++){
            int val=arr[i-1]*arr[k]*arr[j] + solve(i,k,arr) + solve(k+1,j,arr);
            res=min(res,val);
        }
        
        return dp[i][j]= res;
    }
    
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n=arr.size();
        dp.resize(n,vector<int>(n,-1));
        return solve(1,n-1,arr);
        
    }
};