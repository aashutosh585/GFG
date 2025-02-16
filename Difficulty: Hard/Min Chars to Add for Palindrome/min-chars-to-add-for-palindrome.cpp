//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minChar(string& s) {
        // Write your code here
        int n=s.size();
        
        string a=s;
        reverse(a.begin(),a.end());
        s+='$';
        s+=a;
        
        int m=s.size();
        
        vector<int>lps(m,0);
        int pre=0,suf=1;
        while(suf<m){
            if(s[pre]==s[suf]){
                lps[suf]=pre+1;
                suf++,pre++;
            }
            else{
                if(pre==0){
                    lps[suf]=0;
                    suf++;
                }
                else{
                    pre=lps[pre-1];
                }
            }
        }
        return n-lps[m-1];
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.minChar(str);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends