class Solution {
public:
    vector<int> sieve_eratothenes(int num)
    {
        vector<int>isPrime(num+1, 1);
        isPrime[0] = isPrime[1] = 0;
        for(int i=2; i*i<=num; i++)
        {
            if(isPrime[i]==1)
            {
                for(int j=i*i; j<=num; j+=i)
                {
                    isPrime[j]=0;
                }
            }
        }
        return isPrime;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int>isPrime = sieve_eratothenes(right);
        vector<int>primes;
        for(int i=left; i<=right; i++)
        {
            if(isPrime[i]==1)
                primes.push_back(i);
        }
        int mindiff = INT_MAX;
        vector<int>result = {-1, -1};
        for(int i=1; i<primes.size(); i++)
        {
            int diff = primes[i] - primes[i-1];
            if(diff < mindiff)
            {
                mindiff = diff;
                result = {primes[i-1], primes[i]};
            }
        }
        return result;
    }
};