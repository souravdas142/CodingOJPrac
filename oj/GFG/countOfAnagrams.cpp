#include <bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define newln "\n"
#define CODE_PATH  "/home/sourav/Documents/code/"
#define INPUT_FILE CODE_PATH"input.txt"
#define OUTPUT_FILE CODE_PATH"output.txt"
#define ERR_FILE CODE_PATH"err.txt"
#define fixed(n) fixed << setprecision(n)
#define ull unsigned long long
#define ll long long
#define dd double
#define pii pair<int, int>
#define pll pair<long, long>
#define vi vector<int>
#define vl vector<long>
#define vll vector<ll>
#define vvi vector<vi >
#define vvl vector<vl >
#define vvll vector<vll >
#define vpii vector<pii >
#define vpll vector<pll >
#define fr(i,a,b) for(ll i=a;i<b;i++)
#define frr(i,a,b) for(ll i=a-1;i>=b;i--)
#define tr(it,a) for(auto it=a.begin();it!=a.end();it++)
#define sz(a) (ll)((a).size())
#define pb push_back
#define emb emplace_back
#define emp emplace
#define all(x) (x).begin(), (x).end() //Forward traversal
#define rall(x) (x).rbegin, (x).rend() //reverse traversal
#define max(a, b) (a < b ? b : a) 
#define min(a, b) ((a > b) ? b : a) 
#define debug(x) cout<<newln<< #x <<" = "<<x<<endl;
#define debug2(x,y) cout<<newln<< #x <<" = "<<x<<", "<< #y <<" = "<<y<<endl;
#define mod (1e9 + 7)
#define PI 3.1415926535897932384626433832795

template<typename t>
ostream& operator<<(ostream& print,const vector<t> vec) {
    print<<newln<<"{";
    for(auto ele:vec) print<<ele<<", ";
    print<<"} "<<newln;
    return print;
}


class Solution {

    private:

        int countSubPattern(string txt,string pat, unordered_map<string,bool>& ump,int k) {
            int i = 0,j=0;
            int len = txt.length();
            string res = "";
            int cnt = 0;
            while(j<len) {

                while(j<k) {
                    
                    res+=txt[j];
                    if(j==k-1) {
                        if(ump[res]==true) cnt++;
                    }
                    j++;

                }

                res.erase(0,1);
                res+=txt[j];
                if(ump[res]==true) {
                    cnt++;
                }
                j++;i++;
                


            }

            return cnt;
        }
        
        void makeAnagram(string& pat,const int sz,int index,unordered_map<string,bool>& ans)  {
            
            if(index>=sz) {

                //cout<<pat<<endl;
                
                ans[pat]= true;

                return;
            }
            
            for(int i = index;i<sz;i++) {
                swap(pat[index],pat[i]);
                makeAnagram(pat,sz,index+1,ans);
                swap(pat[index],pat[i]);
                
            }
        
            
        }
        
        int anagram(string txt,string pat,int k) {

            unordered_map<string,bool> ans;
            int index = 0;
            int sz = pat.length();

            makeAnagram(pat,sz,index,ans);
            
            //cout<<ans<<endl;
            int cnt = countSubPattern(txt,pat,ans,k);

            return cnt;

        }



    public:
        
        void solve() {

            ll tc = 1;
            //cin>>tc;
    
            while(tc--) {
                
                string txt,pat;
                cin>>txt>>pat;
                int k;cin>>k;
                
                int cnt =  anagram(txt,pat,k);
                
                cout<<cnt<<newln;
              

            }

        }

};



int main() {

    // https://www.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1
    fio;

    #ifndef ONLINE_JUDGE  
        freopen(INPUT_FILE, "r", stdin); 
        //freopen(ERR_FILE, "w", stderr); 
        //freopen(OUTPUT_FILE, "w", stdout); 
    #endif 
    
    Solution sol;
    sol.solve();

    return 0;
}