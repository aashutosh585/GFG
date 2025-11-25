class Solution {
  public:
    int longestBitonicSequence(int n, vector<int> &nums) {
        // code here
        int ans=1;
        
        vector<int>ldp(n,1),rdp(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && ldp[i] < ldp[j]+1){
                    ldp[i]=ldp[j]+1;
                }
            }
        }
        
        for(int i=n-2;i>=0;i--){
            for(int j=n-1;j>i;j--){
                if(nums[i]>nums[j] && rdp[i] < rdp[j]+1){
                    rdp[i]=rdp[j]+1;
                }
            }
        }
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            if(ldp[i] > 1 && rdp[i] > 1) { 
                res=max(res,ldp[i]+rdp[i]-1);
            }
        }

        return res;
    }
};
