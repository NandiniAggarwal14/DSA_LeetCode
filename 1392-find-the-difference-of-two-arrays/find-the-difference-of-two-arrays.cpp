class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        set<int>list1, list2;
        for(int i=0; i<n1; i++)
        {
            list1.insert(nums1[i]);
        }
        for(int i=0; i<n2; i++)
        {
            list2.insert(nums2[i]);
        }
        vector<int>res1;
        vector<int>res2;
        for(auto it: list1)
        {
            if(!(list2.count(it)))
                res1.push_back(it);
        }
        for(auto it: list2)
        {
            if(!(list1.count(it)))
                res2.push_back(it);
        }
        return {res1, res2};
    }
};