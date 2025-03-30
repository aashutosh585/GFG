//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxPartitions(string &s) {
        unordered_map<char, int> mp;
        for(int i = 0; i < s.length(); i++){
            mp[s[i]] = i;
        }
        int totalPartitions = 0;
        int projectedLength = 0;
        int i = 0;
        while(i <= projectedLength && i < s.length()){
            if(i == mp[s[i]]){
                if(i == projectedLength){
                    totalPartitions++;
                    i++;
                    projectedLength++;
                }else{
                    i++;
                }
            }else{
                projectedLength = max(projectedLength, mp[s[i]]);
                i++;
            }
        }
        return totalPartitions;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.maxPartitions(s) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends