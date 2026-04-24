class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>, int>>q;
        vector<vector<int>>vis(n, vector<int>(m, 0));
        int time = 0;
        int freshCount = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i, j}, 0});
                    vis[i][j]=2;
                }
                if(grid[i][j]==1)
                    freshCount++;
            }
        }
        int dummyRow[] = {-1, 0, 1, 0};
        int dummyCol[] = {0, 1, 0, -1};
        int count = 0;
        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            q.pop();
            time = max(time, t);
            for(int i=0; i<4; i++)
            {
                int neighborRow = row+dummyRow[i];
                int neighborCol = col+dummyCol[i];
                if(neighborRow>=0 && neighborRow<n && neighborCol>=0 && neighborCol<m 
                && vis[neighborRow][neighborCol]!=2 && grid[neighborRow][neighborCol]==1)
                {
                    q.push({{neighborRow, neighborCol}, t+1});
                    vis[neighborRow][neighborCol] = 2;
                    count++;
                }
            }
        }
        if(count!=freshCount)
            return -1;
        return time;
    }
};