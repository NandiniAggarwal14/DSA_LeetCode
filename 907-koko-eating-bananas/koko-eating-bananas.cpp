class Solution {
public:
    int max_val(vector<int>&piles)
    {
        int maxi=INT_MIN;
        for(int i=0; i<piles.size(); i++)
        {
            maxi=max(maxi, piles[i]);
        }
        return maxi;
    }

    long long calculate_hours(vector<int>&piles, int h)
    {
        long long hours=0;
        for(int i=0; i<piles.size(); i++)
        {
            hours+= ceil((double)piles[i]/(double)h);
        }
        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1, high=max_val(piles);
        int ans=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            long long hours= calculate_hours(piles, mid);
            if(hours<=h)
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};