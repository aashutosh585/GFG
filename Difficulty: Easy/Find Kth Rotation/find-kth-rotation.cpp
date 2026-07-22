class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int ans=0;
        int st=0, end=arr.size()-1;
        
        while(st<=end){
            int mid=st + (end-st)/2;
            
            if(arr[mid]<arr[ans]) ans=mid;
            
            if(arr[st]<=arr[mid]){
                if(arr[st]<arr[ans]) end=mid-1;
                else st=mid+1;
            }
            else end=mid-1;
        }
        
        return ans;
    }
};
