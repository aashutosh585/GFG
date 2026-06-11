class Solution {
public:
 
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges) {
        if(m==0) return {-1 };
        
        
        // adj list
        vector<vector<pair<int, int>>> adj(n+1);
        for (auto &it : edges) {
            int u=it[0], v= it[1], w= it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        // Dijistra Algorithm
        vector<bool> vis(n+1, 0);
        vector<int>dist(n+1, INT_MAX);
        vector<int>par(n+1, -1);
        
        // now we take min everytime -> priority queue
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
        
        // distance, node
        q.push({0,1});
        dist[1]=0;
        
        while(!q.empty()){
            int x= q.top().second;
            q.pop();
            
            if(vis[x]) continue;
            
            vis[x]=1;
            
            for(auto &it: adj[x]){
                int neg = it.first;
                int w= it.second;
                
                if(!vis[neg] && dist[neg] > w + dist[x]){
                    dist[neg] =w + dist[x];
                    par[neg]=x;
                    q.push({dist[neg], neg});
                }
                
                
            }
        }
        
        // if cannot reach destination
        if(par[n]==-1) return {-1};
        
        // extract shortest path
        vector<int>path;
        int d= n;
        
        while(d!=-1){
            path.push_back(d);
            d=par[d];
        }
        
        path.push_back(dist[n]);
        reverse(path.begin(),path.end());
        
    
        return path;
    }
};