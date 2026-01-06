class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        int n = friends.size();
        int m = order.size();
        unordered_map<int, int>mpp;
        vector<int>ans(n);
        for(int i=0; i<n; i++)
            mpp[friends[i]] = 1;
        int ind=0;
        for(int i=0; i<m ; i++)
        {
            if(mpp.count(order[i]))
            {
                ans[ind] = order[i];
                ind++;
            }
        }
        return ans;
    }
};