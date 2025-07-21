class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>umap;
        vector<int>result;
        for(int i=0; i<nums.size();i++)
        {
            int diff=target-nums[i];
            if(umap.count(diff))
            {
                result.push_back(i);
                result.push_back(umap.find(diff)->second);
            }
            umap[nums[i]]=i;
        }
        return result;
    }
};