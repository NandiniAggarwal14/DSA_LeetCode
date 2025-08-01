class Solution {
public:

    int calculate_score(int i, int j, vector<int>&nums)
    {
        if(i>j)
            return 0;
        if(i==j)
            return nums[i];
        int take_i = nums[i] + min(calculate_score(i+2, j, nums), calculate_score(i+1, j-1, nums));
        int take_j = nums[j] + min(calculate_score(i, j-2, nums), calculate_score(i+1, j-1, nums));
        return max(take_i, take_j);
    } 

    bool predictTheWinner(vector<int>& nums) {
        int total=0;
        for(int i=0; i<nums.size(); i++)
        {
            total+=nums[i];
        }
        int player1= calculate_score(0, nums.size()-1, nums);
        int player2= total-player1;
        return player1>=player2;
    }
};