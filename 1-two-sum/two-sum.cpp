class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int>mpp;
        for(int i=0; i<n; i++)
        {
            if(mpp.count(target-nums[i]))
            {
                return{i, mpp[target-nums[i]]};
            }
            mpp[nums[i]]=i;
        }
        return {};
    }
};