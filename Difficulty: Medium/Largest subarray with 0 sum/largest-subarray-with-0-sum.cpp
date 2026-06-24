class Solution {
  public:
    int maxLength(vector<int>& arr) {
        // code here
        int len=0, n=arr.size();
        unordered_map<int, int>mpp;
        
        int psum=0;
        for(int i=0;i<n;i++){
            psum+=arr[i];
            if(psum==0) len=i+1;
            
            if(mpp.find(psum)!=mpp.end()){
                len=max(len, i-mpp[psum]);
            }
            else
            mpp[psum]=i;
        }
        
        return len;
    }
};