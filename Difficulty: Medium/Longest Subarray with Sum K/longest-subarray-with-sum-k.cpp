class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        int psum=0,len=0;
        unordered_map<int, int>mpp;
        
        for(int i=0;i<n;i++){
            psum+=arr[i];
            if(psum==k) len=i+1;
            
            int val= psum-k;
            if(mpp.find(val)!=mpp.end()){
                len=max(len, i-mpp[val]);
            }
            
            if(mpp.find(psum)==mpp.end()) mpp[psum]=i;
        }
        
        return len;
    }
};