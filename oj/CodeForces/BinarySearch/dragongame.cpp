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

        ll checkPossible(ll n, ll k,ll sec,vector<ll>& arr) {
            ll ans = 0;
            ll prevStart = -1, prevEnd = -1;
            for(ll i = 0;i<n;i++) {
                
                ll k = arr[i]+sec-1;
                if(arr[i]<=prevEnd) {

                    ans+=(k-prevEnd);

                }
                else {
                    prevStart = arr[i];
                    ans+=sec;
                }
                prevEnd = k;
                
            }
            return ans;
        }

        ll killDragon(ll n,ll k, vector<ll>& arr) {

            ll low = 1,high = k;
            while(low<high) {
                ll mid = low+(high-low)/2;

                if(checkPossible(n,k,mid,arr) >= k) {
                    high = mid;
                }
                else {
                    low = mid+1;
                }
            }

            return low;
        }




    public:
        
        void solve() {

            ll tc = 1;
            cin>>tc;
    
            while(tc--) {
                
                ll n,k; cin>>n>>k;
                vector<ll> arr(n);
                for(ll &a:arr) cin>>a;
                ll possible = killDragon(n,k,arr);
                cout<<possible<<newln;

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