class Solution {
  public:
  int n;
  
  
    bool dfs(int i, vector<vector<int>> &adj, vector<bool> &vis, vector<bool> cvis){
        if(n==i) return false;
        
        vis[i]=true;
        cvis[i]=true;
        
        for(auto &it:adj[i]){
            if(cvis[it]) return true;
            
            if(!vis[it]){
                if(dfs(it,adj,vis,cvis)) return true;
            }
        }
        
        
        cvis[i]=false;
        return false;
        
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        n=V;
        vector<vector<int>> adj(V);
        for(auto &it: edges){
            adj[it[0]].push_back(it[1]);
        }
        
        vector<bool>vis(V,false), cvis(V, false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,adj, vis, cvis)) return true;
            }
        }
        
        return false;
        
    }
};