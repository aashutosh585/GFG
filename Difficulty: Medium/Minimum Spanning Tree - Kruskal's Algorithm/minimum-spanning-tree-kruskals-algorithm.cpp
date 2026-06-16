class Solution {
public:

    int parFind(int u, vector<int>& par) {
        return (u == par[u]) ? u : par[u] = parFind(par[u], par);
    }

    void unionByRank(int u, int v, vector<int>& par, vector<int>& rank) {
        int pu = parFind(u, par);
        int pv = parFind(v, par);

        if (pu == pv) return;

        if (rank[pu] > rank[pv]) {
            par[pv] = pu;
        }
        else if (rank[pu] < rank[pv]) {
            par[pu] = pv;
        }
        else {
            par[pv] = pu;
            rank[pu]++;
        }
    }

    int kruskalsMST(int V, vector<vector<int>> &edges) {

        vector<int> par(V);
        vector<int> rank(V, 0);

        for (int i = 0; i < V; i++)
            par[i] = i;

        // Sort edges by weight
        sort(edges.begin(), edges.end(),
            [](vector<int>& a, vector<int>& b) {
                return a[2] < b[2];
            });

        int mstWeight = 0;

        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            if(parFind(u, par) != parFind(v, par)) {
                mstWeight += wt;
                unionByRank(u, v, par, rank);
            }
        }

        return mstWeight;
    }
};