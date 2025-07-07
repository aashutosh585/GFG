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
        
        // vector<bool>visited(V,0);
        
        // stack<int>st;
        // for(int i=0;i<V;i++){
        //     if(!visited[i]){
        //         dfs(i,st,adj,visited);
        //     }
        // }
        
        vector<int>ans;
        // while(!st.empty()){
        //     ans.push_back(st.top());
        //     st.pop();
        // }
        
        
        // find in degree each node
        vector<int>inDeg(V,0);
        for(int i=0;i<V;i++)
        for(int j=0;j<adj[i].size();j++)
        inDeg[adj[i][j]]++;
        
        // indegree whose 0
        queue<int>q;
        for(int i=0;i<V;i++)
        if(!inDeg[i])
        q.push(i);
        
        // remove edge from that indegree
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            
            for(int i=0;i<adj[node].size();i++){
                
                inDeg[adj[node][i]]--;
                if(inDeg[adj[node][i]]==0) q.push(adj[node][i]);
            }
        }
        
        
        return ans;
        
        
    }
};