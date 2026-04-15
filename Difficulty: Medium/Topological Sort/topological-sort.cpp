class Solution {
  public:
  
    void dfs(int i, vector<int>& vis, vector<vector<int>>& adj, stack<int>& st) {
      
        vis[i] = 1;
        for (int it : adj[i]) 
            if (!vis[it]) dfs(it, vis, adj, st);
            
        
        st.push(i);
    }
    
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>adj(V);
        for(auto &it:edges) adj[it[0]].push_back(it[1]);
        
        vector<int>vis(V);
        
        stack<int>st;
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,adj,st);
            }
        }
        
        vector<int>ans;
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
        
        
    }
};