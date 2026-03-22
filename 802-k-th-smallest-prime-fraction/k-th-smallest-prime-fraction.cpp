class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<vector<double>>pq;
        for(int i=0; i<n; i++)
        {
            for(int j = i+1; j<n; j++)
            {
                double div = (double)arr[i]/arr[j];
                pq.push(vector<double>{div, (double)arr[i], (double)arr[j]});
                if(pq.size() > k)
                    pq.pop();
            }
        }
        auto vec = pq.top();
        return {(int)vec[1], (int)vec[2]};
    }
};