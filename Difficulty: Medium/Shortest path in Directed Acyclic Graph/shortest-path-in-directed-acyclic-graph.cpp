class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        
        // adjacency list - neighbor, weight
        vector<vector<pair<int,int>>> adj(V);
        for(auto &it : edges){
            int u = it[0], v = it[1], w = it[2];
            adj[u].push_back({v, w});
        }
        
    
        vector<int> dist(V, INT_MAX);
        vector<bool> vis(V, false);
        
        // Min-Priority Queue - {distance, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        
        // Base case
        dist[0] = 0;
        q.push({0, 0}); 
        
        while(!q.empty()){
            int x = q.top().second;
            q.pop();
            
            if(vis[x]) continue;
            vis[x] = true;
            
            for(auto &it : adj[x]){
                int v = it.first;
                int w = it.second;
                
                if(!vis[v] && dist[v] > dist[x] + w){
                    dist[v] = dist[x] + w;
                    q.push({dist[v], v});
                }
            }
        }
        
        for(int i = 0; i < V; i++){
            if(dist[i] == INT_MAX){
                dist[i] = -1;
            }
        }
        
        return dist;
    }
};