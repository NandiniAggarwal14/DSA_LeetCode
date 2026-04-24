class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!vis[i][j])
                {
                    queue<pair<pair<int, int>, pair<int, int>>>q;
                    q.push({{i, j}, {-1, -1}});
                    vis[i][j] = 1;
                    while(!q.empty())
                    {
                        int row = q.front().first.first;
                        int col = q.front().first.second;
                        int parentrow = q.front().second.first;
                        int parentcol = q.front().second.second;
                        q.pop();
                        for(int i=0; i<4; i++)
                        {
                            int nrow = row + drow[i];
                            int ncol = col + dcol[i];
                            if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && 
                            grid[nrow][ncol]==grid[row][col])
                            {
                                if(vis[nrow][ncol]==0)
                                {
                                    vis[nrow][ncol]=1;
                                    q.push({{nrow, ncol}, {row, col}});
                                }
                                else if(nrow!=parentrow || ncol!=parentcol)
                                    return true;
                            }
                        }
                    }
                }
            }
        }
        return false;
    }
};