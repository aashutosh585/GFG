class Solution {
  public:
    
    int sumOfModes(vector<int>& arr, int k) {
        
        map<int,set<int>,greater<int>> st;   
        unordered_map<int,int> mpp;
        int ans = 0;
        int n = arr.size();

       
        for (int i = 0; i < k-1; i++) {
            int old = mpp[arr[i]];
            if (old > 0) {                           
                st[old].erase(arr[i]);
                if (st[old].empty()) st.erase(old);
            }
            mpp[arr[i]]++;
            st[mpp[arr[i]]].insert(arr[i]);         
        }
        
        int j = 0;
        for (int i = k-1; i < n; i++) {
            int old = mpp[arr[i]];
            if (old > 0) {                           
                st[old].erase(arr[i]);
                if (st[old].empty()) st.erase(old);
            }
            mpp[arr[i]]++;  
            st[mpp[arr[i]]].insert(arr[i]);          
            
            
            ans += *st.begin()->second.begin();     

            int idx = mpp[arr[j]];                 
            st[idx].erase(arr[j]);                   
            if (st[idx].empty()) st.erase(idx);

            mpp[arr[j]]--;                          
            if (mpp[arr[j]] > 0) {
                st[mpp[arr[j]]].insert(arr[j]);     
            } else {
                mpp.erase(arr[j]);                  
            }
            
            j++;
        }
        
        return ans;
    }
};
