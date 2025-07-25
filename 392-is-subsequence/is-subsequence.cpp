class Solution {
public:
    bool isSubsequence(string s, string t) {
   
        int n1=s.length();
        int n2=t.length();
        int p1=0, p2=0;
        while(p1<n1 && p2<n2)
        {
            if(s[p1]==t[p2])
            {
                p1++;
            }
            p2++;
        }
        return(p1==n1);
    }
};