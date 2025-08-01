class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int min_diff=INT_MAX;
        for(int i=1; i<arr.size(); i++)
        {
            int diff=arr[i]-arr[i-1];
            if(diff<min_diff)
                min_diff=diff;
        }
        vector<vector<int>> res;
        for(int i=1; i<arr.size(); i++)
        {
            if((arr[i]-arr[i-1])==min_diff)
                res.push_back({arr[i-1],arr[i]});
        }
        return res;
    }
};