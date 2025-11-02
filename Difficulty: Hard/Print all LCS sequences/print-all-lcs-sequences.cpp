class Solution {
public:
    vector<vector<int>> dp;
    map<pair<int,int>, set<string>> memo;

    int lcsLen(string &a, string &b) {
        int n=a.size(), m=b.size();
        dp.assign(n+1, vector<int>(m+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(a[i]==b[j]) dp[i][j]=1+dp[i+1][j+1];
                else dp[i][j]=max(dp[i+1][j], dp[i][j+1]);
            }
        }
        return dp[0][0];
    }

    set<string> build(int i,int j,string &a,string &b){
        if(i==a.size() || j==b.size())
            return {""};

        if(memo.count({i,j}))
            return memo[{i,j}];

        set<string> result;
        if(a[i]==b[j]){
            for(auto s: build(i+1,j+1,a,b))
                result.insert(a[i]+s);
        } else {
            if(dp[i+1][j] >= dp[i][j+1])
                for(auto s: build(i+1,j,a,b))
                    result.insert(s);
            if(dp[i][j+1] >= dp[i+1][j])
                for(auto s: build(i,j+1,a,b))
                    result.insert(s);
        }
        return memo[{i,j}] = result;
    }

    vector<string> allLCS(string &s1, string &s2) {
        memo.clear();
        int len = lcsLen(s1,s2);
        set<string> all = build(0,0,s1,s2);

        vector<string> res;
        for(auto &x: all)
            if((int)x.size()==len) res.push_back(x);
        return res;
    }
};
