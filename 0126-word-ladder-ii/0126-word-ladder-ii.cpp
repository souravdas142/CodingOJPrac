class Solution {
public:
    void dfs(unordered_map<string,int>& dist,string targetWord, string startWord,vector<string> res, vector<vector<string>>& ans) {
        

        if(targetWord==startWord) {
            reverse(res.begin(),res.end());
            ans.push_back(res);
            reverse(res.begin(),res.end());
            return;
        }

        string v = startWord;
        int sz = v.size();
        for(int i = 0;i<sz;i++) {
            for(char ch = 'a';ch<='z';ch++) {
                v[i] = ch;
                if(dist.count(v) && dist[v]+1 == dist[startWord]) {
                    res.push_back(v);
                    dfs(dist,targetWord,v,res,ans);

                    res.pop_back();
                }
            }
            v = startWord;
        }

    }
    vector<vector<string>> findLadders(string startWord, string targetWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(),wordList.end());
        unordered_map<string,int> dist;
        vector<vector<string>> ans;
        
        dist[startWord] = 1;


        
       
        if(dict.count(targetWord)==0) return ans;
       
        
        queue<string> que;
        que.push(startWord);
        dict.erase(startWord);
        while(!que.empty()) {
            string u = que.front();
            
            que.pop();
            if(targetWord == u) break;
            int len = u.length();
            for(int i = 0;i<len;i++) {
                string temp = u;
                for(char ch = 'a';ch<='z';ch++) {
                    if(ch==u[i]) continue;
                    temp[i] = ch;
                    if(dict.count(temp)!=0) {
                    
                            dist[temp] = dist[u]+1;
                            dict.erase(temp);
                            que.push(temp);
                         
                        
                    }
                }
            }
            
        }
        vector<string> res;
        res.push_back(targetWord);
        dfs(dist,startWord,targetWord,res,ans);
        return ans;
    }
};