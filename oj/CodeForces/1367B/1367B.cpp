#include <bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define newln "\n"
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


class Solutions {

    private:
        
        void solveEvenArray() {
            
            int n; cin>>n;
            vector<int> arr(n);
            int oddcnt = 0;
            for(int& i:arr) {
                cin>>i;
                if(i&1) oddcnt++;
            }
            
            //debug(oddcnt);
            
            if(oddcnt!=n/2) {

                cout<<-1<<newln;
                return;
                
            }
            

            oddcnt = 0;
            
            for(int i = 0; i<n; i+=2) {
                if(arr[i]&1) oddcnt++;
            }

            cout<<oddcnt<<newln;

            
        }



    public:
        
        void solve() {

            ll tc = 1;
            cin>>tc;
    
            while(tc--) {
                
                solveEvenArray();

            }

        }

};



int main() {

    fio;
    
    Solutions sol;
    sol.solve();

    return 0;
}