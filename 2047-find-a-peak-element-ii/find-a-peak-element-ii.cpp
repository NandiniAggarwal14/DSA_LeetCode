class Solution {
public:

    int maximum_row_ele(vector<vector<int>>&mat, int m, int n, int mid)
    {
        int index=-1, maxi=INT_MIN;
        for(int i=0; i<m; i++)
        {
            if(mat[i][mid]>maxi)
            {
                maxi=mat[i][mid];
                index=i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int low=0, high=n-1;
        while(low<=high)
        {
            int mid= (low+high)/2;
            int maxi_ind= maximum_row_ele(mat, m, n, mid);
            int left = mid-1>=0 ? mat[maxi_ind][mid-1] : -1;
            int right = mid+1<n ? mat[maxi_ind][mid+1] : -1;
            if(mat[maxi_ind][mid]>left &&  mat[maxi_ind][mid]>right)
                return {maxi_ind, mid};
            else if(mat[maxi_ind][mid]< left)
                high=mid-1;
            else
                low=mid+1;
        }
        return {-1, -1};
    }
};