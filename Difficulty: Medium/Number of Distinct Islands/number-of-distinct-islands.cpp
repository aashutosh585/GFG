class Solution {
  public:
    int n, m, p, q;
    vector<vector<int>> visit;

    void dfs(int i, int j, vector<vector<int>>& grid, vector<pair<int,int>>& arr) {
        if(i < 0 || j < 0 || i >= n || j >= m) return;
        if(grid[i][j] == 0 || visit[i][j] == 1) return;

        visit[i][j] = 1;
        arr.push_back({i - p, j - q});

     
        dfs(i+1, j, grid, arr);
        dfs(i-1, j, grid, arr);
        dfs(i, j+1, grid, arr);
        dfs(i, j-1, grid, arr);
    }

    int countDistinctIslands(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        visit.assign(n, vector<int>(m, 0));

        set<vector<pair<int,int>>> st;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && visit[i][j] == 0) {
                    vector<pair<int,int>> arr;
                    p = i, q = j;
                    dfs(i, j, grid, arr);
                    st.insert(arr);
                }
            }
        }
        return st.size();
    }
};
