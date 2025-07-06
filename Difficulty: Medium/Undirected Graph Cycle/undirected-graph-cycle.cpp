class Solution {
  public:
    bool dfs(int node,int prev,vector<vector<int>>& adj,vector<bool>&visited){
        visited[node]=1;
    
       
        for(auto it:adj[node]){
            if(prev == it) continue;
            if(visited[it]) return true;
            if(dfs(it,node,adj,visited)) return true;
        }
        
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code her
        vector<bool>visited(V,0);
        
        vector<vector<int>>adj(V);
        
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        for(int i=0;i<V;i++){
            if(!visited[i] && dfs(i,-1, adj, visited)){
                return true;
            }
        }
        
        return false;
        
    }
};