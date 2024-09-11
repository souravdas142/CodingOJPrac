//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        queue<pair<vector<string>,int> > que;
        set<string> sets(wordList.begin(),wordList.end());
       
        int n = beginWord.length();
        int m = wordList.size();
        vector<vector<string> > ans;
        bool trigger = true;

        que.push({vector<string>({beginWord}),1});

        sets.erase(beginWord);
        
        while(!que.empty() && trigger) {

            int sz = que.size();

            queue<string> qst;

            for(int samelevel = 0;samelevel<sz;samelevel++) {

                pair<vector<string>,int> node = que.front();
                vector<string> list = node.first;
                            //cout<<endl;
                            //for(auto a:list) cout<<a<<" -> ";
                            //cout<<endl;
                
                que.pop();

                int dist = node.second;


                string word = list.back();



                for(int i= 0;i<n;i++) {
                    string modword = word;
                    for(char ch='a';ch<='z';ch++) {
                        if(ch==word[i]) continue;
                        modword[i] = ch;
                        if(sets.count(modword)) {
                            list.push_back(modword);
                            que.push({list,dist+1});
                            qst.push(modword);
                            list.pop_back();
                            if(modword==endWord)
                                trigger = false;
                        }
                    }
                }
            }

            while(!qst.empty() && trigger) {
                sets.erase(qst.front());
                qst.pop();
            }







        }

        
       // cout<<que.size()<<endl;
        while(!que.empty()) {
            pair<vector<string>,int> node = que.front();
            que.pop();
            if(node.first.back()==endWord) {
                ans.push_back(node.first);
            }
            
        }

        return ans;
        
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends