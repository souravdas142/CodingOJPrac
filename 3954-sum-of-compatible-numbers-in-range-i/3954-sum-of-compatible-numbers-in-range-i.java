class Solution {
    public int sumOfGoodIntegers(int n, int k) {
        int px = k+n;
        int sum = 0;
        for(int i = 0;i<=px;i++) {
            if(Math.abs(n-i)<=k && (n&i)==0) {
                sum+=i;
            }
        }

        return sum;
    }
}