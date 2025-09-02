class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        vector<int>res(n1);
        vector<int>nextGreater(n2);
        stack<int>st;
        for(int i=n2-1; i>=0; i--)
        {
            while(!st.empty() && nums2[i] >= nums2[st.top()])
                st.pop();
            if(st.empty())
                nextGreater[i]=-1;
            else
                nextGreater[i]=nums2[st.top()];
            st.push(i);
        }
        unordered_map<int, int> mpp;
        for(int i=0; i<n2; i++)
            mpp[nums2[i]] = nextGreater[i];
        for(int i=0; i<n1; i++)
            res[i] = mpp[nums1[i]];
        return res;
    }
};