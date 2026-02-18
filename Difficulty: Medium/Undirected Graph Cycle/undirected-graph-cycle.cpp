class Solution {
  public:
  
    bool dfs(int u, vector<vector<int>>&adj, vector<bool>&visit, int pa){
        visit[u]=true;
        
        for(auto &v:adj[u]){
            if(v==pa) continue;
            if(visit[v]) return true;
            if(dfs(v,adj,visit,u)) return true;
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& ed) {
        // Code here
        vector<vector<int>>adj(V);
        for(int i=0;i<ed.size();i++){
            adj[ed[i][0]].push_back(ed[i][1]);
            adj[ed[i][1]].push_back(ed[i][0]);
        }
        
        vector<bool>visit(V,false);
        for(int i=0;i<V;i++){
            if(!visit[i] && dfs(i,adj,visit,-1)) return true;
        }
        
        return false;
    }
};