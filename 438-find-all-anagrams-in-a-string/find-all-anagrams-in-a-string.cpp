class Solution {
public:
    bool count_zeroes(vector<int>&counter)
    {
        for(int i=0; i<26; i++)
        {
            if(counter[i] != 0)
                return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int>counter(26, 0);
        for(int i=0; i<p.size(); i++)
        {
            char ch = p[i];
            counter[ch-'a']++;
        }
        int i = 0, j = 0;
        int k = p.size();
        vector<int>res;
        while(j<s.size())
        {
            counter[s[j]-'a']--;
            if(j-i+1 == k)
            {
                if(count_zeroes(counter))
                {
                    res.push_back(i);
                }
                counter[s[i]-'a']++;
                i++;
            }
            j++;
        }
        return res;
    }
};