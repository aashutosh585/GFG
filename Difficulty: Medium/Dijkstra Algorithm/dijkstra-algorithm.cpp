class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int s){
        // Code here
        
        // adj list s, w
        vector<vector<pair<int,int>>>adj(V);
        for(auto &it: edges){
            int u = it[0], v = it[1],  w = it[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w}); 
        }
            
        // visit and distance arrays
        vector<int>dist(V, INT_MAX);
        vector<bool>vis(V, false);
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        
        q.push({0,s});
        dist[s]=0;
        
        while(!q.empty()){
            int x= q.top().second;
            q.pop();
            
            if(vis[x]) continue;
            
            vis[x]=true;
            for(auto &it: adj[x]){
                int neg=it.first, w= it.second;
                if(!vis[neg] && dist[neg] > dist[x] + w){
                    dist[neg]= dist[x]+w;
                    q.push({dist[neg],neg});
                }
            }
        }
        
        return dist;
    }
};