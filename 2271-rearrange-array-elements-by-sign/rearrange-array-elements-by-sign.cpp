class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]>0)
                pos.push_back(nums[i]);
            else if(nums[i]<0)
                neg.push_back(nums[i]);
        }
        int l=0, k=0;
        for(int i=0; i<nums.size(); i++)
        {
            if(i%2==0)
            {
                nums[i]=pos[k];
                k++;
            }
            else
            {
                nums[i]=neg[l];
                l++;
            }
        }
        return nums;
    }
};