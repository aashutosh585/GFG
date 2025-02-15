//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> search(string& pat, string& txt) {
        // code here
        vector<int>ans;
        int n=txt.size(),m=pat.size();
        // finding lps 
        vector<int>lps(m);
        int pre=0,suff=1;
        while(suff<m){
            if(pat[pre]==pat[suff]){
                lps[suff]=pre+1;
                suff++,pre++;
            }
            else{
                if(pre==0){
                    lps[suff]=0;
                    suff++;
                }
                else{
                    pre=lps[pre-1];
                }
            }
        }
        
        
            int first=0,second=0;
            while(first<n && second<m){
                if(txt[first]==pat[second]){
                    first++,second++;
                    if(second==m){
                        ans.push_back(first-second);
                        second=lps[second-1];
                    }
                }
                else{
                    if(second==0){
                        first++;
                    }
                    else{
                        second=lps[second-1];
                    }
                }
            }
         
        
        return ans;
        
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector<int> res = ob.search(pat, S);
        if (res.size() == 0)
            cout << "[]" << endl;
        else {
            for (int i : res)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends