#define fio ios_base::sync_with_stdio(false); cin.tie(nullptr);

class Solution {

private:
    bool check(string word1, string word2) {
        int ptr = 0;
        int len = word1.length();
        int cnt = 0;
        while(ptr<len) {
            if(word1[ptr]==word2[ptr]) 
                cnt++;
            ptr++;
        }
        if(len-cnt==1) return true;
        return false;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        fio;
        /// create the graph
        int n = wordList.size();
        unordered_map<string,vector<string> > graph;

        for(int i = 0;i<n;i++) {
            if(check(beginWord,wordList[i])) {
                graph[beginWord].push_back(wordList[i]);
                graph[wordList[i]].push_back(beginWord);
            }
        }

        for(int i= 0;i<n;i++) {
            for(int j = i+1;j<n;j++) {
                //if(i==j) continue;
                if(check(wordList[i],wordList[j])) {
                    graph[wordList[i]].push_back(wordList[j]);
                    graph[wordList[j]].push_back(wordList[i]);
                }
            }
        }

        queue<pair<string,int> > que;
        unordered_map<string,bool> visited;
        que.push({beginWord,1});
        visited[beginWord] = true;

        while(!que.empty()) {
            pair<string,int> node = que.front();
            que.pop();
            if(node.first==endWord) return node.second;
            for(auto str:graph[node.first]) {
                if(!visited[str]) {
                    visited[str] = true;
                    int dst = node.second+1;
                    que.push({str,dst});
                }
            }
        }

        return 0;

    }
};