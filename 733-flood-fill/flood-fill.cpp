class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& res, vector<vector<int>>& image, int initial, int color,
    int dummyRow[], int dummyCol[])
    {
        res[row][col] = color;
        int n = image.size();
        int m = image[0].size();
        for(int i=0; i<4; i++)
        {
            int nrow = row + dummyRow[i];
            int ncol = col + dummyCol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==initial && res[nrow][ncol]!=color)
            {
                dfs(nrow, ncol, res, image, initial, color, dummyRow, dummyCol);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int initial = image[sr][sc];
        vector<vector<int>>res = image;
        int dummyRow[] = {-1, 0, 1, 0};
        int dummyCol[] = {0, 1, 0, -1};
        dfs(sr, sc, res, image, initial, color, dummyRow, dummyCol);
        return res;
    }
};