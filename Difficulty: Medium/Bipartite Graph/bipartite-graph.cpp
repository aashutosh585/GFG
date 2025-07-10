class Solution {
  public:
    bool dfs(int node,bool flag,vector<vector<int>>&adj, set<int>&st1 ,set<int>&st2,vector<bool>&visited){
        if(!flag){
            st1.insert(node);
        }
        else{
            st2.insert(node);
        }
        
        visited[node] = 1;
        
        for (int nei : adj[node]) {
            if (!visited[nei]) {
                if (!dfs(nei, !flag, adj, st1, st2, visited))
                return false;
            }
            else {
                if(!flag && st1.count(nei)) return false;
                if( flag && st2.count(nei)) return false;
            }
        }
        
        return true;
        
    }
    
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        vector<vector<int>>adj(V);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        set<int>st1,st2;
        
        vector<bool>visited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(!dfs(i,false,adj,st1,st2,visited))
                   return false;
            }
        }
        
        
        return true;
        
    }
};