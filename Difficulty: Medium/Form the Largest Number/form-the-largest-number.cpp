class Solution {
  public:
    string findLargest(vector<int> &arr) {
        // code here
        sort(arr.begin(),arr.end(),[](int a, int b){
            string s1=to_string(a);
            string s2 = to_string(b);
            return s1+s2 > s2+s1;
        });
        
        string ans;
        int zcnt=0;
        
        for(auto it:arr){
            ans+=to_string(it);
            if(it==0) zcnt++;
        }
        
        if(zcnt==arr.size()) return "0";
        
        return ans;
    }
};