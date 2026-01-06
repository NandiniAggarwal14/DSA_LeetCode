class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(2*n);
        int ind=0;
        for(int i=0; i<n; i++)
            ans[ind++]=nums[i];
        for(int i=0; i<n; i++)
            ans[ind++]=nums[i];
        return ans;
    }
};