class Solution {
public:
    void seivePrime(int num,unordered_map<int,bool>& primes)  {
        
        vector<int> seive(num+1,0);
        //seive[0] = 1, seive[1] = 1;

        for(int i = 3;i*i<=num;i+=2) {
            if(seive[i]==0) {
                for(int j = i*i;j<=num;j+=(i*2)) {
                    seive[j] = 1;
                }
            }
        }

        for(int i = 2;i<=num;i++) {
            if(seive[i]==0) {
                primes[i] = true;
            }
        }

    }
    bool checkPrimeFrequency(vector<int>& nums) {

        unordered_map<int,int> ump;
        int n = nums.size();
        for(auto e: nums) ump[e]++;

        unordered_map<int,bool> primes;

        seivePrime(n,primes);

        for(auto ele: ump) {
            int freq = ele.second;

            if(primes.find(freq)!=primes.end()) return true;

            
        }

        return false;
        
    }
};