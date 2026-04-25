class Solution {
public:
    int helper(int n, int step, vector<int>&dp)
    {
        if(step==n)
        {
            return 1;
        }
        if(step>n)
            return 0;
        if(dp[step]!=-1)
        {
            return dp[step];
        }
        else
            dp[step] = helper(n, step+1, dp) +  helper(n, step+2, dp);
        return dp[step];
    }
    int climbStairs(int n) {
        vector<int>dp(46, -1);
        return helper(n, 0, dp);
    }
};