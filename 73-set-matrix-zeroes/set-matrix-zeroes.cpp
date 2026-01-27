class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<pair<int, int>>count;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(matrix[i][j]==0)
                    count.push_back({i,j});
            }
        }
        int size = count.size();
        for(int i=0; i<size; i++)
        {
            int row = count[i].first;
            int col = count[i].second;
            for(int j=0; j<n; j++)
            {
                matrix[j][col]=0;
            }
            for(int j=0; j<m; j++)
            {
                matrix[row][j]=0;
            }
        }
    }
};