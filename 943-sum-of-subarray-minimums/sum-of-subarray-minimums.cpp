class Solution {
public:
    vector<int>nextSmaller(vector<int>& arr)
    {
        int n=arr.size();
        vector<int>nse(n);
        stack<int>st;
        for(int i=n-1; i>=0; i--)
        {
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            nse[i] =st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int>prevSmallerOrEqual(vector<int>& arr)
    {
        int n=arr.size();
        vector<int>pse(n);
        stack<int>st;
        for(int i=0; i<n; i++)
        {
            while(!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            pse[i] =st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>nse(n);
        vector<int>pse(n);
        nse=nextSmaller(arr);
        pse=prevSmallerOrEqual(arr);
        long long total=0;
        int mod = (int)(1e9 + 7);
        for(int i=0; i<n; i++)
        {
            long long left = i-pse[i];
            long long right = nse[i]-i;
            total=(total + (right * left * arr[i])%mod)%mod;
        }
        return (int)total;
    }
};