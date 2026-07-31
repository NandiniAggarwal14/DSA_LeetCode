class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int max_count = 0, count, max_row=0;
        int m = mat.size();
        int n = mat[0].size();
        for(int i=0; i<m; i++)
        {
            count = 0;
            for(int j=0; j<n; j++)
            {
                if(mat[i][j]==1)
                {
                    count++;
                }
            }
            if(max_count<count)
            {
                max_count = count;
                max_row = i;
            }
        }
        return {max_row, max_count};
    }
};