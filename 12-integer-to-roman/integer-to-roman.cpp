class Solution {
public:
    string intToRoman(int num) {
        vector<string> roman = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        vector<int> nums = {1000, 900, 500, 400, 100, 90,50, 40, 10, 9, 5, 4, 1};
        string res="";
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            while(num%nums[i]!=num)
            {
                int div = num/nums[i];
                for(int j=0; j<div; j++)
                {
                    res+=roman[i];
                }
                num=num%nums[i];
            }
        }
        return res;
    }
};