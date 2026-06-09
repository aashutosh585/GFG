class Solution {
public:
    string findOrder(vector<string> &words) {

        vector<vector<int>> adj(26);
        vector<int> indegree(26, 0);
        vector<bool> present(26, false);

        for (auto &word : words) {
            for (char ch : word) {
                present[ch - 'a'] = true;
            }
        }

        int n = words.size();

        for (int i = 0; i < n - 1; i++) {

            string &s1 = words[i];
            string &s2 = words[i + 1];

            int len = min(s1.size(), s2.size());
            int j = 0;

            while (j < len && s1[j] == s2[j])
                j++;

            // invalid prefix case
            if (j == len) {
                if (s1.size() > s2.size())
                    return "";
                continue;
            }

            int u = s1[j] - 'a';
            int v = s2[j] - 'a';

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;

        int total = 0;

        for (int i = 0; i < 26; i++) {
            if (present[i]) {
                total++;

                if (indegree[i] == 0)
                    q.push(i);
            }
        }

        string ans;

        while (!q.empty()) {

            int u = q.front();
            q.pop();

            ans.push_back(u + 'a');

            for (int v : adj[u]) {

                indegree[v]--;

                if (indegree[v] == 0)
                    q.push(v);
            }
        }

        if (ans.size() != total)
            return "";

        return ans;
    }
};