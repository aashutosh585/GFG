// User function Template for C++

class Solution {
  public:
    vector<string>ans;
    
    void generate(string s,int n){
        if(s.size()==n){
            ans.push_back(s);
            return;
        }
        
        if(s[s.size()-1]=='1'){
            
            generate(s+'0',n);
        } 
        else{
            generate(s+'0',n);
            generate(s+'1',n);
        }
        
    }
    vector<string> generateBinaryStrings(int n) {
        // Write your code
        generate("",n);
        return ans;
        
    }
};