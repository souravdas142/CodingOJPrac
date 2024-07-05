#include <bits/stdc++.h>   
#include <complex> 
#include <queue> 
#include <set> 
#include <unordered_set> 
#include <list> 
#include <chrono> 
#include <random> 
#include <iostream> 
#include <algorithm> 
#include <cmath> 
#include <string> 
#include <vector> 
#include <map> 
#include <unordered_map> 
#include <stack> 
#include <iomanip> 
#include <fstream> 
using namespace std;

#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln

/*
* prime naive
* check if X is prime
*  the first method is to check from 2 to X-1 if is divisible
* then if it is divisible the X is not prime
* 
* But is it really feasible  its almost O(n)
* 
* The better idea is to iterate upto sqrt(n)
* becase X=a*b then either a, or b has to be
* a<=sqrt(x) 
*/


bool isPrime(int x) {

    if(x==2) return true;


    if(!(x&1)) return false;



    for(int i=3;i*i<=x;i+=2) {

        dbg(i);

        if(!(x%i)) return false;


    }
    return true;
}

int main() {

   int t,n; cin>>t;
   while(t--) {
    cin>>n;

        if(isPrime(n))
            cout<<n<<" : is Prime"<<"\n";
        else
            cout<<n<<" : is not Prime"<<"\n";
   }

    return 0;

}