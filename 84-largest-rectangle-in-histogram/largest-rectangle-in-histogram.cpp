class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
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
};