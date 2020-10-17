#include <vector>
class Solution {
public:
        vector<char> stk;
        vector<bool> vis;
        vector<string> ans;

    void dfs(string s, vector<bool> &vis, vector<char> &stk, int d, 
            vector<string> &ans) {
        int i;

        if (d == s.size()) {
            std::string temp(stk.begin(), stk.end());
            ans.push_back(temp);
            return ;
        }

        for (i = 0; i < s.size(); i++) {
            if (!vis[i]) {
                vis[i] = true;
                stk.push_back(s[i]);
                dfs(s, vis, stk, d+1, ans);
                stk.pop_back();
                vis[i] = false;
            }
        }
        
    }
    vector<string> permutation(string S) {
        //char *str = S.c_str();
/*
        for (std::vector<bool>::iterator it = vis.begin() ; it != vis.end(); ++it) {
            *it = false;
        }
        */
        vis.resize(S.size() + 1);
        vis.clear();
        ans.clear();
        stk.clear();
        dfs(S, vis, stk, 0, ans);
        return ans;
    }
};