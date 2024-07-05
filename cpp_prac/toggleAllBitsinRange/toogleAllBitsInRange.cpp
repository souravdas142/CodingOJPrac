#include <iostream>
#include <bitset>

using namespace std;
#define bitDraw(x) cout<<#x<<" is: "<<bitset<10>(x)<<"\n";

int main() {
    
    int a,b,x; cin>>a>>b>>x;
    int bitMask1=(1<<(a-1))-1;
    bitDraw(bitMask1);
    int bitMask2=~((1<<b)-1);
    bitDraw(bitMask2);
    int bitmask=bitMask1&bitMask2;

    bitDraw(x);
    bitDraw(bitmask);
    x=x^bitmask;
    bitDraw(x);
    




    return 0;
}