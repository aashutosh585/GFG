class Solution {
  public:
    vector<vector<int>>dp;
    
    int solve(int idx,vector<int>&arr,int target){
        
        if(idx==arr.size()){
            if(target==0) return 1;
            else return 0;
            
        } 
    
        
        if(target<0) return 0;
        
        
        if(dp[idx][target]!=-1) return dp[idx][target];
        
        int take=solve(idx+1,arr,target-arr[idx]);
        int ntake =solve(idx+1,arr,target);
        
        return dp[idx][target]=take+ntake;
    }
    
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        dp.resize(n,vector<int>(target+1,-1));
        
        return solve(0,arr,target);
        
    }
};