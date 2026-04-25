class Solution {
public:
    int helper(vector<int>& nums, vector<int>&dp, int n , int ind)
    {
        if(ind==n || ind>n)
            return 0;
        if(dp[ind]!=-1)
        {
            return dp[ind];
        }
        dp[ind] = max(helper(nums, dp, n, ind+1), nums[ind]+helper(nums, dp, n, ind+2));
        return dp[ind];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, -1);
        return max(helper(nums, dp, n, 0), helper(nums, dp, n, 1));
    }
};