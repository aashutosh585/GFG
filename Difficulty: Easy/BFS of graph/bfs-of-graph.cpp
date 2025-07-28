class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        int n=adj.size();
        queue<int>q;
        vector<bool>visited(n,false);
        vector<int>ans;
        
        q.push(0);
        while(!q.empty()){
            int node =q.front();
            q.pop();
            
            if(!visited[node])
            ans.push_back(node);
            
            visited[node]=true;
            
            for(auto it :adj[node]){
                if(!visited[it]){
                    q.push(it);
                }
            }
        }
        
        return ans;
        
        
    }
};