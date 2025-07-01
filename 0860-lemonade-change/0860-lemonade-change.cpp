class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

        unordered_map<int,int> d = {{5,0},{10,0},{20,0}};

        int n = bills.size();
        int price = 5;

        for(int i= 0;i<n;i++) {
            
            int change = bills[i] - price;
            
            if(bills[i] == 10) {

                if(d[5]>0) {
                    d[5]--;
                    change -= 5;
                }
                else return false;
                
            }
            else if(bills[i]==20) {
                if(d[10] > 0) {
                    d[10]--;
                    change = change-10;
                }
                if(d[5] >= change/5) {
                    d[5] -= (change/5);
                    change -= (5*(change/5));
                }
                else {
                    return false;
                }
            } 

            d[bills[i]]++;

        }
        return true;
        
    }
};