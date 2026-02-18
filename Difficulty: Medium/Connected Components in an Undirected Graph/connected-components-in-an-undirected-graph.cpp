class Solution {
public:
    void dfs(int i, vector<vector<int>> &adj, vector<bool>& visit, vector<int>& arr) {
        if(visit[i]) return;
        visit[i] = true;
        arr.push_back(i);

        for(auto &it : adj[i]) {
            dfs(it, adj, visit, arr);
        }
    }

    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V), res;

        for(auto &it : edges) {
            int a = it[0], b = it[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<bool> visit(V, false);

        for(int i = 0; i < V; i++) {
            if(!visit[i]) {
                vector<int> arr;
                dfs(i, adj, visit, arr);
                res.push_back(arr);
            }
        }

        return res;
    }
};
