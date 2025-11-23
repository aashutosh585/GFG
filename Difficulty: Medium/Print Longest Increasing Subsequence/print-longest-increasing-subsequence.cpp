class Solution {
  public:
    vector<int> getLIS(vector<int>& arr) {
        // Code here
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
        for(int i=n-1;i>=0;i--){
            for(int pi=i-1;pi>=-1;pi--){
                int l=0;
                if(pi==-1 || arr[pi]<arr[i]) l=1+dp[i+1][i+1];
                int r=dp[i+1][pi+1];
                dp[i][pi+1]=max(l,r);
            }
        }
        
        vector<int>ans;
        int i=0,pi=-1;
        while(i<n){
            if(pi==-1 || arr[pi]<arr[i]){
                int l=1+dp[i+1][i+1];
                int r=dp[i+1][pi+1];
                if(l>=r){
                    ans.push_back(arr[i]);
                    pi=i;
                }
            }
            i++;
        }
        
        
        return ans;
    }
};