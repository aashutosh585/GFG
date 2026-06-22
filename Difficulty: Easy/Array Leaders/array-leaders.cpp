class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        // code here
        int n=arr.size(), x=-1;
        vector<int>res;
        
        for(int i=n-1;i>=0;i--){
            if(x <= arr[i]){
                x=arr[i];
                res.push_back(x);
            }
        }
        reverse(res.begin(), res.end());
        
        return res;
        
        
    }
};