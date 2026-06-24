class Solution {
  public:
    long subarrayXor(vector<int> &nums, int k) {
        // code here
        int pxor=0, n=nums.size();
        unordered_map<int, int>mpp;
        
        int res=0;
        
        for(int i=0;i<n;i++){
            pxor ^= nums[i];
            
            if(pxor==k) res++;
            
            int val= pxor^k;
            if(mpp.find(val)!=mpp.end()){
                res+= mpp[val];
            }
            
            mpp[pxor]++;
        }
        
        return res;
    }
};