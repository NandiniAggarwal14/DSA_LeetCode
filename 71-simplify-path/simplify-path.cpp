class Solution {
public:
    string simplifyPath(string path) {
        string token = "";
        stringstream ss(path);
        vector<string>st;
        while(getline(ss, token, '/'))
        {
            if(token == "" || token == ".") continue;
            if(token!="..")
                st.push_back(token);
            else
                if(!st.empty()) 
                    st.pop_back();
        }
        if(st.empty())
            return "/";
        string res = "";
        for(auto &t:st)
        {
            res += "/" + t;
        }
        return res;
    }
};