class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        
        // index, cost
        vector<vector<pair<int, int>>> adj(V);
        for(auto &it: edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        // vector<int>par(V,-1);
        vector<bool>vis(V,false);
        
        // cost, index, parent
        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        >q;
        
        q.push({0,0});
        int cost=0;
        int x,y;
        
        while(!q.empty()){
            auto it=q.top();
            q.pop();
            
            x=it[0], y= it[1];
            
            if(vis[y]) continue;
            cost+=x;
            vis[y]=true;
       
            
            for(auto [i,w]: adj[y]){
                if(!vis[i]){
                    q.push({w, i});
                }
            }
            
            
        }
        
        return cost;
            
        
        
        
        
    }
};