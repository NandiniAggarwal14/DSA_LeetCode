class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int>mp;
        int left = 0, right = 0, maxlen = 0;
        while(right<n)
        {
            if(mp.count(s[right]) && mp[s[right]]>=left)
            {
                left = mp[s[right]] + 1;
            }
            maxlen = max(maxlen, right-left+1);
            mp[s[right]]=right;
            right++;
        }
        return maxlen;
    }
};