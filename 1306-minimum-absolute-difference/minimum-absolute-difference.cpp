class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int min_diff = INT_MAX;
        for(int i=0; i<n-1; i++)
        {
            int diff = arr[i+1] - arr[i];
            if(diff < min_diff)
                min_diff = diff;
        }
        vector<vector<int>>res;
        for(int i=0; i<n-1; i++)
        {
            if(arr[i+1] - arr[i] == min_diff)
                res.push_back({arr[i], arr[i+1]});
        }
        return res;
    }
};