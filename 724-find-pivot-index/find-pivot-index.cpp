class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int>sum(n, 0);
        sum[0] = nums[0];
        for(int i=1; i<n; i++)
        {
            sum[i] = sum[i-1]+nums[i];
        }
        int left = 0;
        int curr = nums[0];
        for(int i=0; i<n; i++)
        {
            if(left==sum[n-1]-curr)
                return i;
            left=sum[i];
            curr=sum[i+1];
        }
        return -1;
    }
};