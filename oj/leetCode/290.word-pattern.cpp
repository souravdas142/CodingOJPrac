/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 */

// @lc code=start
class Solution {
public:
    bool wordPattern(string pattern, string s) {
    stringstream ss(s);
    string ts;
    vector<string> vs;
    while(getline(ss,ts,' ')) {
        vs.push_back(ts);
    }
    
    int psz = pattern.length();
    int vsz = vs.size();
    if(psz!=vsz) {
        return false;
    }
    
    unordered_map<char,set<string> > ump;
    
    for(int i = 0;i<psz;i++) {
        ump[pattern[i]].insert(vs[i]);
        if(ump[pattern[i]].size()>1) {
            return false;
        }
    }
    
    return true;
    }
};
// @lc code=end

