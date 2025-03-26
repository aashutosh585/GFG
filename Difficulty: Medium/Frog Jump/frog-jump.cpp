//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int>dp;
    int way(int i,vector<int>&height){
        int n=height.size();
        if(i>=n) return 0;
        
        if(dp[i]!=-1) return dp[i];
        
        int ans=INT_MAX;
        if(i+1<n)
        ans=min(ans,abs(height[i]-height[i+1])+way(i+1,height));
        
        if(i+2<n)
        ans=min(ans,abs(height[i]-height[i+2])+way(i+2,height));
        
        if(ans==INT_MAX)
        return 0;
        else
        return dp[i]= ans;
    }
    int minCost(vector<int>& height) {
        // Code here
        dp.resize(height.size(),-1);
        return way(0,height);
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends