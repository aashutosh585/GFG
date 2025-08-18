// User function Template for C++

class Solution {
  public:
    int distinct(string &s,int idx){
        int total=0;
        vector<int>previous(26,0);
        for(int i=0;i<s.size();i++){
            int present=total+1;
            if(previous[s[i]-'a']){
                total+=present-previous[s[i]-'a'];
            } else{
                total+=present;
            }
            previous[s[i]-'a'] = present;
        }
       return total;
    }
    
    string betterString(string &s1, string &s2) {
        // code here
        return distinct(s1,0) >= distinct(s2,0)? s1:s2;
        
    }
};