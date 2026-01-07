class Solution {
public:
    int findXorSum(vector<int>&nums, int i, int xr)
    {
        if(i==nums.size())
            return xr;
        int pick = findXorSum(nums, i+1, xr^nums[i]);
        int no_pick = findXorSum(nums, i+1, xr);
        return pick + no_pick;
    }
    int subsetXORSum(vector<int>& nums) {
        return findXorSum(nums, 0, 0);
    }
};