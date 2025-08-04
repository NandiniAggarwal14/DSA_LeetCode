class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();

        for(int i=0; i<m; i++){
            int n=matrix[0].size();
            int low=0, high=n-1;
            if(target>=matrix[i][0] && target<=matrix[i][n-1])
            while(low<=high){
                int mid=(low+high)/2;

                if(matrix[i][mid]==target)
                    return true;
                else if(matrix[i][mid]>target)
                    high=mid-1;
                else
                    low=mid+1;
            }
        }

        return false;
    }
};