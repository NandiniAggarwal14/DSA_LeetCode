class Solution {
public:
    int largest(vector<int>& heights) {
        int n=heights.size();
        stack<int>st;
        int maxi=0;
        int nse, pse, ele;
        for(int i=0; i<n; i++)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
            {
                ele = st.top();
                st.pop();
                nse = i;
                pse = st.empty() ? -1 : st.top();
                maxi = max(maxi, heights[ele] * (nse - pse - 1));
            }
            st.push(i);
        }
        while(!st.empty())
        {
            ele = st.top();
            st.pop();
            nse = n;
            pse = st.empty() ? -1 : st.top();
            maxi = max(maxi, heights[ele] * (nse - pse - 1));
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxi = 0;
        vector<int> heights(m, 0);
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
            {
                if (matrix[i][j] == '1')
                    heights[j] += 1;
                else
                    heights[j] = 0;
            }
            maxi = max(maxi, largest(heights));
        }
        return maxi;
    }
};