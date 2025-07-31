class Solution {
  public:
    int wordLadderLength(string startWord, string targetWord,
                         vector<string>& wordList) {
        // Code here
        unordered_map<string,bool> dict;
        unordered_map<string,int> dist;
        
        for(auto& s: wordList) {
            dict.insert({s,true});
            dist.insert({s,INT_MAX});
        }
        
        
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
                        if(dist[u]+1<dist[temp]) {
                            dist[temp] = dist[u]+1;
                            que.push(temp);
                        }
                    }
                }
            }
            
        }
        
        return (dist[targetWord]==INT_MAX)?0:dist[targetWord];
    }
};