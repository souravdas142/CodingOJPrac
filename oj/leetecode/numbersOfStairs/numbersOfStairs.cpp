#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define newln "\n"
#define debug(x) cout<<newln<<#x<<" = "<<x<<newln



class Solution {

    public:
        
        static ll resolveFact(ll n,vector<ull>& factTable, ll result,ll preVectIndex) {
            if(n<2) return 1;
            if(n==preVectIndex) return result;
            result = result*n;
            factTable[n]=result;
            return resolveFact(n-1,factTable,result,preVectIndex);
        }

        static void solve(ll n,vector<ull>& factTable,ll preVectIndex=1) {
            
            ull result = factTable[preVectIndex];
            if(factTable[n]==0) {
                resolveFact(n,factTable,result,preVectIndex);
            }
            
            // ncr {nc1,nc2} = n!/(1!*(n-1)!) n!/(2!*(n-2)!)
            ll res = factTable[n]/factTable[n-1];
            res+=(factTable[n]/(2*factTable[n-2]));
            
            cout<<result<<endl;
            
            




        }


};

int main() {

    ll tc =1;
    cin>>tc;
    vector<ull> factorialTable;
    while(tc--) {
        ll n; cin>>n;
        factorialTable.resize(n);
        Solution::solve(n,factorialTable);
    }
    
    return 0;

}

