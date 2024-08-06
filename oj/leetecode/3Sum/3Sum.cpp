#include <bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define newln "\n"
#define INPUT_FILE "/home/sourav/Documents/code/input.txt"
#define OUTPUT_FILE "/home/sourav/Documents/code/output.txt"
#define ERR_FILE "/home/sourav/Documents/code/err.txt"
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
#define fi first
#define se second
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
        
        vi solve3Sum(vi& arr,int n,int target) {

            vi ans;
            for(int i = 0;i<n;i++) {
                map<int,int> mp;
                for(int j = i+1;j<n;j++) {
                    
                    int need = target-(arr[i]+arr[j]);
                    if(mp.find(need)!=mp.end()) {
                        
                        ans = vi({i,j,mp[need]});

                    }
                    
                    mp.insert({arr[j],j});
                    
                }
            }
            
            return ans;
            
        }



    public:
        
        void solve() {

            ll tc = 1;
            cin>>tc;
    
            while(tc--) {
                
                int n; cin>>n;
                debug(n);
                vector<int> arr(n);
                int t; cin>>t;
                for(int &a:arr) cin>>a;

                vi ans = solve3Sum(arr,n,t);
                
                cout<<ans<<endl;
                

            }

        }

};



int main() {

    fio;
    
    /* This is needed as most contests use this format */
    #ifndef ONLINE_JUDGE  
    	freopen(INPUT_FILE, "r", stdin); 
    	//freopen("error.txt", "w", stderr); 
    	//freopen("output.txt", "w", stdout); 
    	//If you dont need error.txt, remove it
    #endif 
    
    Solution sol;
    sol.solve();

    return 0;
}