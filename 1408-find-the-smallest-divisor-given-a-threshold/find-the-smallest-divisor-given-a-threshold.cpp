class Solution {
public:

    int max_ele(vector<int>&nums)
    {
        int maxi=INT_MIN;
        for(int i=0; i<nums.size(); i++)
            maxi=max(maxi,nums[i]);
        return maxi;
    }

    int calculate_sum(vector<int>&nums, int mid)
    {
        int sum=0;
        for(int i=0; i<nums.size(); i++)
        {
            sum+=ceil((double)nums[i]/double(mid));
        }
        return sum;

    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1, high=max_ele(nums);
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(calculate_sum(nums, mid)<=threshold)
                high=mid-1;
            else
                low=mid+1;
        }
        return low;
    }
};