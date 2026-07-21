class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        // code here
        int a1=-1, a2=INT_MAX;
        for(int i=0;i<arr.size(); i++){
            if(arr[i]<=x && a1<arr[i]) a1=arr[i];
            if(arr[i]>=x && a2>arr[i]) a2=arr[i];
        }
        if(a2==INT_MAX) a2=-1; 
        return {a1,a2};
    }
};