class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        int e=adj.size();
        
        vector<int>ans;
        vector<bool>visited(e,0);
        queue<int>pq;
        
        if(e==0) return ans;
        
        pq.push(0);
        while(!pq.empty()){
            int x = pq.front();
            pq.pop();
            
            if(!visited[x])
            ans.push_back(x);
            
            visited[x]=1;
            
            for(auto it:adj[x]){
                if(!visited[it])
                pq.push(it);
            }
        }
        
        return ans;
    }
};