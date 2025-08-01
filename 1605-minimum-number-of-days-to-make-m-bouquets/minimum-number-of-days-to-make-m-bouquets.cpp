class Solution {
public:

    bool isPossible(int mid, vector<int>&bloomDay, int m, int k)
    {
        int count=0, bouquets=0;
        for(int i=0; i<bloomDay.size(); i++)
        {
            if(bloomDay[i]<=mid)
                count++;
            else
            {
                bouquets+=(count/k);
                count=0;
            }
        }
        bouquets+=(count/k);
        return bouquets>=m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = m*1LL * k*1LL;
        if(val>bloomDay.size())
            return -1;
        int mini= INT_MAX, maxi= INT_MIN;
        for(int i=0; i<bloomDay.size(); i++)
        {
            mini=min(mini, bloomDay[i]);
            maxi=max(maxi, bloomDay[i]);
        }
        int low=mini, high= maxi;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(isPossible(mid, bloomDay, m, k))
                high=mid-1;
            else
                low=mid+1;
        }
        return low;
    }
};