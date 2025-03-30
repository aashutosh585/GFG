//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<vector<vector<int>>>dp;
    int collect(int ai,int bi,int l,vector<vector<int>>& grid){
        int n=grid.size(),m=grid[0].size();
        if(l==n) return 0;
        
        if(dp[l][ai][bi] != -1) return dp[l][ai][bi];
        
        int ans=grid[l][ai]+grid[l][bi],y=0;
        
        if(ai-1>=0 && ai-1<m ){
            int x=0;
            if(bi-1>=0 && bi-1<m && ai-1!=bi-1){
                x=max(x,collect(ai-1,bi-1,l+1,grid));
            }
            if(bi>=0 && bi<m && ai-1!=bi){
                x=max(x,collect(ai-1,bi,l+1,grid));
            }
            if(bi+1>=0 && bi+1<m && ai-1!=bi+1){
                x=max(x,collect(ai-1,bi+1,l+1,grid));
            }
            y=max(y,x);
        }
        if(ai>=0 && ai<m){
            int x=0;
            if(bi-1>=0 && bi-1<m && ai!=bi-1){
                x=max(x,collect(ai,bi-1,l+1,grid));
            }
            if(bi>=0 && bi<m && ai!=bi){
                x=max(x,collect(ai,bi,l+1,grid));
            }
            if(bi+1>=0 && bi+1<m && ai!=bi+1){
                x=max(x,collect(ai,bi+1,l+1,grid));
            }
            y=max(y,x);
        }
        if(ai+1>=0 && ai+1<m){
            int x=0;
            if(bi-1>=0 && bi-1<m && ai+1!=bi-1){
                x=max(x,collect(ai+1,bi-1,l+1,grid));
            }
            if(bi>=0 && bi<m && ai+1 !=bi){
                x=max(x,collect(ai+1,bi,l+1,grid));
            }
            if(bi+1>=0 && bi+1<m && ai+1!=bi+1){
                x=max(x,collect(ai+1,bi+1,l+1,grid));
            }
            y=max(y,x);
        }
        return dp[l][ai][bi]=ans+y;
    }
    int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
        dp.resize(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return collect(0,grid[0].size()-1,0,grid);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends