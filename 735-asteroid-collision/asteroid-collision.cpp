class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>res;
        int n =asteroids.size();
        for(int i=0; i<n; i++)
        {
            while(!res.empty() && res.back()>0 && asteroids[i]<0 && res.back() < abs(asteroids[i]))
                res.pop_back();
            if(!res.empty() && asteroids[i]<0 && res.back()==abs(asteroids[i]))
                res.pop_back();
            else if(res.empty() || res.back()<0 || asteroids[i]>0)
                res.push_back(asteroids[i]);
        }
        return res;
    }
};