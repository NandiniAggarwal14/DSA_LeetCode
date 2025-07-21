class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        unordered_set<int>st;
        for(int i=0; i<nums.size(); i++)
            st.insert(nums[i]);
            int longest=1;
        for(auto it:st)
        {
            if(!st.count(it-1))
            {
                int x=it;
                int count=1;
                while(st.count(x+1))
                {
                    x++;
                    count++;
                }
                longest=max(longest, count);
            }
        }
        return longest;
    }
};