class Solution {
private: 
    void bfs(int row, int col, vector<vector<char>>&grid, vector<vector<int>>&vis)
    {
        int n = grid.size();
        int m = grid[0].size();  
        vis[row][col] = 1;
        queue<pair<int, int>>q;
        q.push({row, col});
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0; i<4; i++)
            {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]=='1')
                {
                    bfs(nrow, ncol, grid, vis);
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>>vis(n, vector<int>(m, 0));
        for(int row=0; row<n; row++)
        {
            for(int col=0; col<m; col++)
            {
                if(!vis[row][col] && grid[row][col] == '1')
                {
                    count++;
                    bfs(row, col, grid, vis);
                }
            }
        }
        return count;
    }
};