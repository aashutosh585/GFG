class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        // code here
        
        if(arr[arr.size()-1]<x) return -1;
        
        int ans=arr.size();
        int l=0, h=arr.size()-1;
        
        while(l<=h){
            int mid= l + (h-l)/2;
            
            if(arr[mid]>=x){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        
        return ans;
    }
};