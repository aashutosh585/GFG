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
        // recursive
        // dp.resize(n,vector<int>(n,-1));
        // return solve(1,n-1,arr);
        
        // tabulation
        dp.resize(n,vector<int>(n,0));
        
        for(int i=n-1;i>0;i--){
            for(int j=i+1;j<n;j++){
                int res=1e9;
                for(int k=i;k<j;k++){
                    int val=arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];
                    res=min(res,val);
                }
                dp[i][j]=res;
            }
        }
        
        return dp[1][n-1];
        
        
        
    }
};