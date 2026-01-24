class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount<1)
            return 0;
        int n = coins.size();
        vector<int>minCoins(amount+1);
        for(int i=1; i<=amount; i++)
        {
            minCoins[i] = INT_MAX;
            for(int j=0; j<n; j++)  
            {
                if(coins[j]<=i && minCoins[i-coins[j]]!=INT_MAX)
                    minCoins[i]=min(minCoins[i], 1+minCoins[i-coins[j]]);
            }      
        }
        if (minCoins[amount]==INT_MAX)
            return -1;
        return minCoins[amount];
    }
};