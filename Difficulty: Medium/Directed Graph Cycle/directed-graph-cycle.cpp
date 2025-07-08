class Solution {
  public:
    
    bool dfs(int node,vector<vector<int>>&adj,vector<bool>&path,vector<int>&visited){
        path[node]=1;
        visited[node]=1;
        
        for(auto it:adj[node]){
            if(path[it]) return 1;
            if(!visited[it]) continue;
            if(dfs(it,adj,path,visited)) return 1;
        }
        
        path[node]=0;
        
        return false;
    }
    
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<bool>path(V,0);
        vector<vector<int> >adj(V);
        vector<int>visited(V,0);
        
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        
        for(int i=0;i<V;i++){
            if(!visited[i] && dfs(i,adj,path,visited))
            return true;
        }
        return false;
    }
};