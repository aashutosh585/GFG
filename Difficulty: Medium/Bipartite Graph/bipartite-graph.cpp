class Solution {
  public:
  
    bool dfs(int node,int c,vector<vector<int>>&adj, vector<int>&color){
        
       color[node]=c;
       
        for(auto it:adj[node]){
            if(color[it]==-1){
               if(!dfs(it,!c,adj,color)) return false;
            }
            else{
                if(color[it]==c) return false;
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
        
        vector<int>color(V,-1);
        
        for(int i=0;i<V;i++){
            if(color[i]==-1){
                if(!dfs(i,0,adj,color))
                   return false;
            }
        }
        
        
        return true;
        
    }
};