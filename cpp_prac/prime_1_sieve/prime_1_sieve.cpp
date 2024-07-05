
#include <bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ln "\n"
#define dbg(x) cout<<#x<<" is: "<<x<<ln;


int main() {
    //fio;
    int t; cin>>t; 
    while (t--) {
        int x; cin>>x;
        vector<bool> container(x+1,true);
        
        /*
         * nieve prime
        */
        int sqrt_x = sqrt(x);
        vector<int> nieve_prime;
        for(int j=3;j<sqrt_x;j+=2) {
            bool flag=false;
            for(int i=3;i*i<=j;i+=2){
                if(j%i==0) {flag=true;break;}
            }
            if(!flag)
                nieve_prime.emplace_back(j);
        }
        
        cout<<__LINE__<<ln;

       // sieve
       // 
       cout<<endl;
       for(int i:nieve_prime) cout<<i<<" ";
       cout<<endl;
       
       for(int i = 2;i<=x;i+=2) container[i] = false;

        for(int a:nieve_prime) {
            for(int i=3*a;i<=x;i+=2*a) {
                
                if(container[i])
                    container[i] = false;
                //else
                    //dbg(i);
            }
        }
        
        for(int i = 0;i<=x;i++) {
            if(container[i]) 
                cout<<i<<" ";
        }
        cout<<endl;

        
        
        
    }

    return 0;







}