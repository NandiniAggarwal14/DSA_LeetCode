class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int>mpp;
        for(int i=0; i<arr.size(); i++)
        {
            mpp[arr[i]]++;
        }
        priority_queue<int, vector<int>, greater<int>>pq;
        for(auto it:mpp)
        {
            pq.push(it.second);
        }
        while(!pq.empty() && k>0)
        {
            int freq = pq.top();
            pq.pop();
            if(k>=freq)
            {
                k-=freq;
            }
            else
            {
                pq.push(freq);
                break;
            }
        }
        return pq.size();
    }
};