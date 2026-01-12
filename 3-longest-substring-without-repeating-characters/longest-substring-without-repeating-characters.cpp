class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        int maxlen = 0;
        for(int i=0; i<len; i++)
        {
            vector<int>hash(255, 0);
            for(int j=i; j<len; j++)
            {
                if(hash[s[j]]==1)
                    break;
                int l = j-i+1;
                maxlen = max(maxlen, l);
                hash[s[j]]=1;
            }
        }
        return maxlen;
    }
};