class Solution {
public:
    int minSteps(vector<int>& arr, int start, int end) {
        vector<int> dist(1000, INT_MAX);
        queue<pair<int,int>> q; // {value, steps}

        q.push({start, 0});
        dist[start] = 0;

        while(!q.empty()) {
            auto [curr, s] = q.front();
            q.pop();

            if(curr == end)
                return s;

            for(int x : arr) {
                int next = (curr * x) % 1000;

                if(dist[next] > s+ 1) {
                    dist[next] = s + 1;
                    q.push({next, s + 1});
                }
            }
        }

        return -1;
    }
};