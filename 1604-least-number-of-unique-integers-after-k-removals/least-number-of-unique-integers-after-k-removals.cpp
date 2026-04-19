class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int>mpp;
        for(int i=0; i<arr.size(); i++)
        {
            mpp[arr[i]]++;
        }
        vector<pair<int, int>>vec;
        for(auto it:mpp)
        {
            vec.push_back({it.second, it.first});
        }
        int count=0;
        sort(vec.begin(), vec.end());
        for(int i=0; i<vec.size(); i++)
        {
            if(vec[i].first<=k)
            {
                k-=vec[i].first;
                count++;
            }
            else
                return vec.size()-count;
        }
        return vec.size()-count;
    }
};