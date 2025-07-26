class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int preProd=1, suffProd=1;
        int maxi=INT_MIN;
        for(int i=0; i<nums.size(); i++)
        {
            if(preProd==0)
                preProd=1;
            if(suffProd==0)
                suffProd=1;
            preProd *=nums[i];
            suffProd*=nums[nums.size()-i-1];
            maxi=max(maxi, max(preProd, suffProd));
        }
        return maxi;
    }
};