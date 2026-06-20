class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int r1=-1, r2=-1;
        for(int i=0;i<arr.size();i++){
            if(r1<=arr[i]){
                if(r1!=arr[i]) r2=max(r2,r1); 
                r1=arr[i];
            }
            else {
                r2=max(r2,arr[i]);
            }
            
        }
        return r2;
    }
};