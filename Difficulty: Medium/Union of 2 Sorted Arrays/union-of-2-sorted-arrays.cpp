class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // code here
        int i=0, j=0,k=-1, n=a.size(), m= b.size();
        vector<int>arr;
        
        while(i<n && j<m){
            int mn=min(a[i],b[j]);
            while(i<n && mn==a[i]) i++;
            while(j< m && mn==b[j]) j++;
            
            if(arr.size()==0 || mn>arr[arr.size()-1]) arr.push_back(mn);
        }
        
        while(i<n){
            if(arr.size()==0 || a[i]>arr[arr.size()-1])
            arr.push_back(a[i]);
            
            i++;
        }
        while(j<m){
            if(arr.size()==0 || b[j]>arr[arr.size()-1])
            arr.push_back(b[j]);
            
            j++;
        }
        
        return arr;
    }
};