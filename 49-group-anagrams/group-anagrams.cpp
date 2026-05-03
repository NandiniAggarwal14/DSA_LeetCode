class Solution {
public:
    string generate(string &word)
    {
        int arr[26] = {0};
        for(char ch: word)
        {
            arr[ch-'a']++;
        }
        string newword = "";
        for(int i=0; i<26; i++)
        {
            int freq = arr[i];
            newword += string(freq, i+'a');
        }
        return newword;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>>mp;
        vector<vector<string>>res;
        for(int i=0; i<n; i++)
        {
            string word = strs[i];
            string newword = generate(word);
            mp[newword].push_back(word);
        }
        for(auto it: mp)
        {
            res.push_back(it.second);
        }
        return res;
    }
};