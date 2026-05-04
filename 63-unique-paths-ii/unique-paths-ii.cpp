class Solution {
public:
    int solve(int n, int m, vector<vector<int>>& obstacleGrid, vector<vector<int>>&dp)
    {
        if(n<0 || m<0)
            return 0;
        if(obstacleGrid[n][m]==1)
            return 0;
        if(dp[n][m]!=-1)
            return dp[n][m];
        if(n==0 && m==0)
            return 1;
        return dp[n][m] = solve(n-1, m, obstacleGrid, dp) + solve(n, m-1, obstacleGrid, dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return solve(n-1, m-1, obstacleGrid, dp);
    }
};