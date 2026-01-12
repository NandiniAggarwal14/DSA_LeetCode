class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        int maxlen = 0;
        int r=0, l=0;
        vector<int>hash(256, -1);
        while(r<len)
        {
            if(hash[s[r]]!=-1)
            {
                if(hash[s[r]]>=l)
                    l = hash[s[r]] + 1;
            }
            int length = r - l + 1;
            maxlen = max(maxlen, length);
            hash[s[r]]=r;
            r++;
        }
        return maxlen;
    }
};