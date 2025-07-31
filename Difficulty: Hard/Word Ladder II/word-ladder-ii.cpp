// User function Template for C++

class Solution {
  public:
  
    void dfs(unordered_map<string,set<string>>& parent, string targetWord, string startWord,vector<string> res, vector<vector<string>>& ans) {
        res.push_back(startWord);
        if(startWord == targetWord) {
            reverse(res.begin(),res.end());
            ans.push_back(res);
            return;
        }
            
        for(auto& s: parent[startWord]) {
            
            dfs(parent,targetWord,s,res,ans);
        }
    }
  
    vector<vector<string>> findSequences(string startWord, string targetWord,
                                         vector<string>& wordList) {
        // code here
                // Code here
        unordered_map<string,bool> dict;
        unordered_map<string,int> dist;
        vector<vector<string>> ans;
        
        unordered_map<string,set<string>> parent;
        
        for(auto& s: wordList) {
            dict.insert({s,true});
            dist.insert({s,INT_MAX});
        }
        if(dict.find(targetWord)==dict.end()) return ans;
        
        dist.insert({startWord,1});
        dist[startWord] = 1;
        
        queue<string> que;
        que.push(startWord);
        
        while(!que.empty()) {
            string u = que.front();
            
            que.pop();
            
            int len = u.length();
            for(int i = 0;i<len;i++) {
                string temp = u;
                for(char ch = 'a';ch<='z';ch++) {
                    if(ch==u[i]) continue;
                    temp[i] = ch;
                    if(dict.find(temp)!=dict.end()) {
                        if(dist[u]+1<=dist[temp]) {
                            dist[temp] = dist[u]+1;
                            que.push(temp);
                            parent[temp].insert(u);
                        }
                    }
                }
            }
            
        }
        vector<string> res;
        dfs(parent,startWord,targetWord,res,ans);
        return ans;
    }
};