class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        unordered_map<int, int>mp;
        int count=1;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]==x)
            {
                mp[count]=i;
                count++;
            }
        }
        vector<int>res;
        for(int i=0; i<queries.size(); i++)
        {
            if(mp.count(queries[i]))
            {
                res.push_back(mp[queries[i]]);
            }
            else
                res.push_back(-1);
        }
        return res;
    }
};