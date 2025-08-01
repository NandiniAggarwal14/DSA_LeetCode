class Solution {
public:

    int max_calc(vector<int>&weights)
    {
        int maxi=INT_MIN;
        for(int i=0; i<weights.size(); i++)
            maxi=max(maxi, weights[i]);
        return maxi;
    }
    int sum_all(vector<int>&weights)
    {
        int sum=0;
        for(int i=0; i<weights.size(); i++)
            sum+=weights[i];
        return sum;
    }

    int find_cap(vector<int>&weights, int mid)
    {
        int load=0, days=1;
        for(int i=0; i<weights.size(); i++)
        {
            if(load+weights[i]>mid)
            {
                days++;
                load=weights[i];
            }
            else
                load+=weights[i];
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=max_calc(weights);
        int high=sum_all(weights);
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(find_cap(weights, mid)<=days)
                high=mid-1;
            else
                low=mid+1;
        }
        return low;
    }
};