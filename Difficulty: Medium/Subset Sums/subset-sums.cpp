class Solution {
  public:
    void solve(vector<int>&ans,vector<int>arr,int sum,int idx){
        if(idx==arr.size()){
            ans.push_back(sum);
            return;
        }
        
        solve(ans,arr,sum,idx+1);
        solve(ans,arr,sum+arr[idx],idx+1);
    }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int>ans;
        solve(ans,arr,0,0);
        return ans;
    }
};