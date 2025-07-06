class Solution {
  public:
    
    void dfs(int node,stack<int>&st,vector<vector<int>>& adj,vector<bool>&visited){
        visited[node]=1;
        
        for(auto it:adj[node]){
            if(!visited[it])
            dfs(it,st,adj,visited);
        }
        
        st.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>adj(V);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
        }
        
        vector<bool>visited(V,0);
        
        stack<int>st;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,st,adj,visited);
            }
        }
        
        vector<int>ans;
        while(!st.empty()){
            // cout<<""<<st.top()<<""<<endl;
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
        
        
    }
};