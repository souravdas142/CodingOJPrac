class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int> wordlevel;
        unordered_set<string> usets(wordList.begin(),wordList.end());
        vector<vector<string > > ans;
        if(!usets.count(endWord)) return ans;
        int n = beginWord.length();
        queue<string> que;
        que.push(beginWord);
        wordlevel[beginWord] = 0;
        int minsteps = 0;
        usets.erase(beginWord);

        while(!que.empty()) {
            string word = que.front();
            que.pop();
            if(word == endWord) {
                minsteps = wordlevel[word];
                break;
            }


            for(int i= 0;i<n;i++) {
                string modword = word;
                for(char ch = 'a';ch<='z';ch++) {
                    modword[i] = ch;
                    if(modword==word) continue;
                    
                    if(usets.count(modword)) {
                        usets.erase(modword);
                        que.push(modword);
                        wordlevel[modword] = wordlevel[word]+1;
                    }

                }

            }





        }

        

        
        vector<string> res;
        int level = minsteps;
        res.push_back(endWord);
        

        findSequence(wordlevel,n,level,res,ans);

        return ans;

    }
    void findSequence(unordered_map<string,int>& wordlevel,int n,int level,vector<string> res, vector<vector<string> >& ans) {

        if(level<=0) {
          //  res.push_back(beginWord);
            reverse(res.begin(),res.end());
            ans.push_back(res);
            return;
        }
        string word = res.back();

        for(int i = 0;i<n;i++) {
            string modword = word;
            for(char ch='a';ch<='z';ch++) {
                modword[i] = ch;
                if(modword==word) continue;
                if(wordlevel.count(modword) && wordlevel[modword]<wordlevel[word]) {
                    res.push_back(modword);
                    findSequence(wordlevel,n,level-1,res,ans);
                    res.pop_back();
                }
            }
        }

    }
};