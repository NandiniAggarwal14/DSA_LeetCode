class Solution {
private:
    void dfs(string src, string dest, unordered_map<string, vector<pair<string, double>>>&adj, unordered_set<string>&vis, double prod, double &ans)
    {
        if(vis.count(src))
            return;
        if(src == dest)
        {
            ans = prod;
            return;
        }
        vis.insert(src);
        for(auto &it: adj[src])
        {
            string next = it.first;
            double val = it.second;
            dfs(next, dest, adj, vis, prod*val, ans);
        }
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n=equations.size();
        unordered_map<string, vector<pair<string, double>>>adj;
        for(int i=0; i<n; i++)
        {
            string u=equations[i][0];
            string v=equations[i][1];
            double val = values[i];
            adj[u].push_back({v, val});
            adj[v].push_back({u, 1/val});
        }
        vector<double>res;
        for(auto &it: queries)
        {
            string src = it[0];
            string dest = it[1];
            double ans = -1.0;
            double prod = 1.0;
            if(adj.count(src))
            {
                unordered_set<string> vis;
                dfs(src, dest, adj, vis, prod, ans);
            }
            res.push_back(ans);
        }
        return res;
    }
};