ostream& operator<<(ostream& print,vector<int>& p) {
    for(auto e: p) {
        print<<e<<" ";
    }
    return print;
}

class Solution {
public:
    vector<int> longestCommonPrefix(vector<string>& words) {

        int n = words.size();
        int i = 0, j = 1;
        vector<int> adjcmn(n,0);
        vector<int> ans(n,0);
        
        while(j<n) {
            string word1 = words[i];
            string word2 = words[j];

            int p1 = 0, p2 = 0;
            
            while(word1!=word2 && p1<word1.size() && p2<word2.size()) {
                if(word1[p1]==word2[p2]) {
                    p1++;
                    p2++;
                }
                else {
                    break;
                }
            }

            if(word1!=word2)
                adjcmn[i] = p1;
            else
                adjcmn[i] = word1.size();


            i++;j++;
        }

        vector<int> prefix(n,0);
        vector<int> sufix(n,0);
        //cout<<adjcmn<<endl;
        int maxLeft = 0;
        for(int i = 1;i<n;i++) {
            if(adjcmn[i-1]>maxLeft) maxLeft = adjcmn[i-1];
            prefix[i] = maxLeft;
        }
        
        int maxRight = 0;
        for(int i = n-1;i>=0;i--) {
            if(adjcmn[i]>maxRight) maxRight = adjcmn[i];
            sufix[i] = maxRight;
        }

        ans[0] = sufix[1];
        ans[n-1] = prefix[n-2];

        for(int i = 1;i<n-1;i++) {
            string word1 = words[i-1];
            string word2 = words[i+1];
            int p1 = 0, p2 = 0;
            while(word1!=word2 && p1<word1.size() && p2<word2.size()) {
                if(word1[p1] == word2[p2]) {
                    p1++; p2++;
                }
                else {
                    break;
                }
            }
            int curSize = (word1==word2)?word1.size():p2;
            ans[i] = max(prefix[i-1],max(sufix[i+1],curSize));
        }
       

        return ans;
        
    }
};