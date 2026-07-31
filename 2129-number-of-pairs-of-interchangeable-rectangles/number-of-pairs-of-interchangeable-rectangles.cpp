class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        int m = rectangles.size();
        unordered_map<double, long long>mp;
        long long count = 0;
        for(int i=0; i<m; i++)
        {
            double var = (double)rectangles[i][0]/rectangles[i][1];
            count += mp[var];
            mp[var]++;
        }
        return count;
    }
};