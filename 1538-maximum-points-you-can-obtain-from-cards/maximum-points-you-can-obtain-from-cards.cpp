class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = 0, maxsum = 0;
        for(int i=0; i<k; i++)
        {
            sum+=cardPoints[i];
        }
        maxsum = max(sum, maxsum);
        for(int i=0; i<k; i++)
        {
            sum -= cardPoints[k-i-1];
            sum += cardPoints[n-i-1];
            maxsum = max(sum, maxsum);
        }
        return maxsum;
    }
};