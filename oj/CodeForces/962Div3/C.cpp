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

    vector<vector<int> > freq1, freq2;
    private:

        void print() {
            cout<<"\n------freq1------\n";
            for(int i=0;i<freq1.size();i++) {
                for(int j = 0;j<26;j++) {
                    cout<<freq1[i][j]<<" ";
                }
                cout<<newln;
            }
            cout<<"------freq1------\n";
            cout<<"\n------freq2------\n";
            for(int i=0;i<freq2.size();i++) {
                for(int j = 0;j<26;j++) {
                    cout<<freq2[i][j]<<" ";
                }
                cout<<newln;
            }
            cout<<"------freq1------\n\n";
        }
        void constructprefix(int n) {
            freq1 = vector<vector<int> > (n+1,vector<int>(26,0));
            freq2 = vector<vector<int> > (n+1,vector<int>(26,0));
            string a,b; cin>>a>>b;

            /// need to avoid re calculation every query

            for(int i = 1;i<=n;i++) {
                freq1[i] = freq1[i-1];
                freq1[i][a[i-1]-'a']++;
            }


            for(int i = 1;i<=n;i++) {
                freq2[i] = freq2[i-1];
                freq2[i][b[i-1]-'a']++;
            }


        }

        void takeQuery(int query) {
            while(query--) {
                int l,r; cin>>l>>r;
                solveEachquery(l,r);

            }
        }

        void solveEachquery(int l, int r) {
            vector<int> freq3(26,0),freq4(26,0);
            
            int cnt = 0,diffn = 0;
            for(int i = 0 ;i<26;i++) {
                freq3[i] = abs(freq1[r][i] - freq1[l-1][i]);
                freq4[i] = abs(freq2[r][i] - freq2[l-1][i]);
                if(freq3[i]!=freq4[i]) {
                    diffn++;
                    cnt+=abs(freq3[i]-freq4[i]);
                }
            }

            if(diffn==0) diffn = 1;
/*
            cout<<"\n-----freq3-----\n";
            for(int a:freq3) cout<<a<<" ";
            cout<<"\n-----freq3-----\n";
            cout<<"\n-----freq4-----\n";
            for(int a:freq4) cout<<a<<" ";
            cout<<"\n-----freq4-----\n";
*/
            cout<<(cnt/diffn)<<newln;
        }


    public:
        
        void solve() {

            ll tc = 1;
            cin>>tc;
    
            while(tc--) {
                int n,q; cin>>n>>q;
                constructprefix(n);
 //               print();
                takeQuery(q);
                //TODO: queryImpl gand marao abhi

            }

        }

};



int main() {

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