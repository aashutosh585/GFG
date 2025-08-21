class Solution {
  public:
    vector<string> ans;
    
    void solve(int row, int col, vector<vector<int>>& maze, vector<vector<bool>>& visited, string s) {
        int n = maze.size();

        if (row == n-1 && col == n-1) {
            ans.push_back(s);
            return;
        }
        
        visited[row][col] = true;
        
        int dx[] = {1, 0, 0, -1};
        int dy[] = {0, -1, 1, 0};
        char d[] = {'D', 'L', 'R', 'U'};
        
        for (int i = 0; i < 4; i++) {
            int nr = row + dx[i];
            int nc = col + dy[i];
            
 
            if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                maze[nr][nc] == 1 && !visited[nr][nc]) {
                solve(nr, nc, maze, visited, s + d[i]);
            }
        }

        visited[row][col] = false;
    }
    
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();

        if (maze[0][0] == 0) return ans;
        
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        solve(0, 0, maze, visited, "");

        return ans;
    }
};
