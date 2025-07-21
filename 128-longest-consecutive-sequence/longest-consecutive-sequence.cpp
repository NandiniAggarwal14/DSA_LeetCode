class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        sort(nums.begin(), nums.end());
        int count =0;
        int lastSmallest=INT_MIN;
        int longest=1;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]-1==lastSmallest)
            {
                count++;
                lastSmallest=nums[i];
            }
            else if(nums[i]!=lastSmallest)
            {
                count =1;
                lastSmallest=nums[i];
            }
            longest=max(longest, count);
        }
        return longest;
    }
};