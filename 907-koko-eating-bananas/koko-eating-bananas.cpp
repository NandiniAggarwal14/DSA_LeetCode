class Solution {
public:
    int max_ele(vector<int>&piles)
    {
        int maxi = INT_MIN;
        int n = piles.size();
        for(int i = 0; i< n; i++)
        {
            maxi = max(piles[i], maxi);
        }
        return maxi;
    }
    long long required_hours(vector<int>&piles, int mid)
    {
        long long tot = 0;
        int n = piles.size();
        for(int i=0; i<n; i++)
        {
            tot += ceil((double)piles[i]/(double)mid);
        }
        return tot;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = max_ele(piles);
        while(low<=high)
        {
            int mid = (low + high)/2;
            long long total_hours = required_hours(piles, mid);
            if(total_hours <= h)
                high = mid-1;
            else
                low = mid+1;
        }
        return low;
    }
};