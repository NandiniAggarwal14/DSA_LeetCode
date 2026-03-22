class Solution {
public:
    bool isPrime(int n)
    {
        if(n<=1)
            return false;
        for(int i=2; i<=n/2; i++)
        {
            if(n%i==0)
                return false;
        }
        return true;
    }
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(auto i:nums)
        {
            freq[i]++;
        }
        for(auto it:freq)
        {
            if(isPrime(it.second))
                return true;
        }
        return false;
    }
};