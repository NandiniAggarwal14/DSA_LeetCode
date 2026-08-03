class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++)
        {
            sum+=nums[i];
        }
        if(x == sum)
            return n;
        int val = sum - x;
        if(x>sum)
            return -1;
        int maxi = -1;
        int left = 0;
        sum = 0;
        for(int i=0; i<n; i++)
        {
            sum+=nums[i];
            while(sum > val)
            {
                sum -= nums[left];
                left++;
            }
            if(sum == val)
            {
                maxi = max(maxi, i-left+1);
            }
        }
        if(maxi == -1)
            return maxi;
        else
            return n-maxi;
    }
};