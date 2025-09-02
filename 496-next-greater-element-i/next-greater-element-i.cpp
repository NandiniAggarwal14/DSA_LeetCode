class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res(nums1.size());
        vector<int>nextGreater(nums2.size());
        stack<int>st;
        for(int i=nums2.size()-1; i>=0; i--)
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
        for(int i=0; i<nums2.size(); i++)
            mpp[nums2[i]] = nextGreater[i];
        for(int i=0; i<nums1.size(); i++)
            res[i] = mpp[nums1[i]];
        return res;
    }
};