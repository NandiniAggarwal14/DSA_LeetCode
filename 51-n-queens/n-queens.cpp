class Solution {
public:
    bool isValid(int row, int col, vector<string>&board)
    {
        int temp_r, temp_c;
        temp_r=row;
        temp_c=col;
        while(temp_c >= 0)
        {
            if(board[temp_r][temp_c]=='Q')
                return false;
            temp_c--;
        }
        temp_r=row;
        temp_c=col;
        while(temp_c >= 0 && temp_r < board.size())
        {
            if(board[temp_r][temp_c]=='Q')
                return false;
            temp_c--;
            temp_r++;
        }
        temp_r=row;
        temp_c=col;
        while(temp_c >= 0 && temp_r >=0)
        {
            if(board[temp_r][temp_c]=='Q')
                return false;
            temp_c--;
            temp_r--;
        }
        return true;
    }
    void compute_res(int col,int n,vector<string> &board, vector<vector<string>> &res)
    {
        if(col==n)
        {
            res.push_back(board);
            return;
        }
        for(int i=0; i<n; i++)
        {
            if(isValid(i, col, board))
            {
                board[i][col]='Q';
                compute_res(col+1, n, board, res);
                board[i][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>res;
        vector<string>board(n);
        string str(n, '.');
        for(int i=0; i<n; i++)
            board[i]=str;
        compute_res(0, n, board, res);
    return res;
    }
};