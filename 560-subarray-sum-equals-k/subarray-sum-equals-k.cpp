class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        mp[0]=1;
        int presum=0, count=0;
        for(int i=0; i<nums.size(); i++)
        {
            presum+=nums[i];
            int del=presum-k;
            count+=mp[del];
            mp[presum]+=1;
        }
        return count;
    }
};