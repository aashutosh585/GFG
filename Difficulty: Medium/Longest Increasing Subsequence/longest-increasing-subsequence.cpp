class Solution {
  public:
    int lis(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
        for(int i=n-1;i>=0;i--){
            for(int pi=i-1;pi>=-1;pi--){
                int tak=0;
                if(pi==-1 || arr[i]>arr[pi]) tak=1+dp[i+1][i+1];
                int ntak=dp[i+1][pi+1];
                dp[i][pi+1]=max(tak,ntak);
            }
        }
        return dp[0][0];
    }
};