class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& ed) {
        // code here
        
        vector<vector<int>>adj(V);
        for(auto &it:ed) adj[it[0]].push_back(it[1]);
        
        queue<int>q;
        vector<int>deg(V),ans;
        
        for(int i=0;i<V;i++)
            for(int j=0;j<adj[i].size();j++)
                deg[adj[i][j]]++;
                
        
        for(int i=0;i<V;i++) if(deg[i]==0) q.push(i); 
    
        
        while(!q.empty()){
            int n=q.front();
            q.pop();
            
            ans.push_back(n);
            
            
            for(int &it:adj[n]){
                deg[it]--;
                if(deg[it]==0) q.push(it);
            }
            
        }
        
        return ans;
        
    }
};