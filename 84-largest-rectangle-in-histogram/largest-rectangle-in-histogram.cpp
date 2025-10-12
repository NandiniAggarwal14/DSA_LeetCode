class Solution {
public:
    vector<int>findNSE(vector<int> &heights)
    {
        int n=heights.size();
        vector<int>res(n, n);
        stack<int>st;
        for(int i=n-1; i>=0; i--)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
                st.pop();
            if(!st.empty())
                res[i]=st.top();
            st.push(i);
        }
        return res;
    }
    vector<int>findPSE(vector<int> &heights)
    {
        int n=heights.size();
        vector<int>res(n, -1);
        stack<int>st;
        for(int i=0; i<n; i++)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
                st.pop();
            if(!st.empty())
                res[i]=st.top();
            st.push(i);
        }
        return res;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>nse = findNSE(heights);
        vector<int>pse = findPSE(heights);
        int maxi=INT_MIN;
        for(int i=0; i<n; i++)
        {
            maxi = max(maxi, heights[i] * (nse[i] - pse[i] - 1));
        }
        return maxi;
    }
};