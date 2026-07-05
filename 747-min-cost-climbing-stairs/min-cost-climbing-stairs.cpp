class Solution {
public:
    int helper(int i, vector<int>& cost, int n, vector<int>&dp)
    {
        if(i>=n)
            return 0;
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        return dp[i] = cost[i]+ min(helper(i+1, cost, n, dp), helper(i+2, cost, n, dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n,-1);
        return min(helper(0, cost, n, dp), helper(1, cost, n, dp));
    }
};