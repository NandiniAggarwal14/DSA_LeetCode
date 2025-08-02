class Solution {
public:
    int max_ele(vector<int>&nums)
    {
        int maxi=INT_MIN;
        for(int i=0; i<nums.size(); i++)
            maxi=max(maxi, nums[i]);
        return maxi;
    }

    int sum_calc(vector<int>&nums)
    {
        int sum=0;
        for(int i=0; i<nums.size(); i++)
            sum+=nums[i];
        return sum;
    }

    int calc_sub(vector<int>& nums, int mid)
    {
        int count=1;
        long long sub=0;
        for(int i=0; i<nums.size(); i++)
        {
            if(sub+nums[i]<=mid)
            {
                sub+=nums[i];
            }
            else
            {
                count++;
                sub=nums[i];
            }
        }
        return count;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=max_ele(nums);
        int high=sum_calc(nums);
        while(low<=high)
        {
            int mid=(low+high)/2;
            int noOfSubarrays= calc_sub(nums, mid);
            if(noOfSubarrays>k)
               low=mid+1;
            else
                high=mid-1; 
        }
        return low;
    }
};