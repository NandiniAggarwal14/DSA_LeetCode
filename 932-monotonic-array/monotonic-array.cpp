class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        if(n==0 || n==1)
            return true;
        int index = 0;
        for(int i=0; i<n-1; i++)
        {
            if(nums[i]!=nums[i+1])
            {
                index = i;
                break;
            }
        }
        int diff = nums[index]-nums[index+1];
        index+=1;
        while(index<n-1)
        {
            if(diff< 0 && (nums[index]-nums[index+1]) >0)
                return false;
            else if(diff > 0 && (nums[index]-nums[index+1])<0)
                return false;
            else
            {
                index++;
                continue;
            }
        }
        return true;
    }
};