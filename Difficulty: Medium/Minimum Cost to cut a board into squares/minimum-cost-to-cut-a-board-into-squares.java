class Solution {
    public static int minCost(int n, int m, int[] x, int[] y) {
        // code here
        int xs = x.length;
        int ys = y.length;
        int h = 1;
        int v = 1;
        Arrays.sort(x);
        Arrays.sort(y);
        int i = xs-1;
        int j = ys-1;
        int totalsum = 0;
        while(i>=0 && j>=0) {
            int sum = 0;
            if(x[i]>y[j]) {
                sum = (x[i] * h);
                v+=1;
                i--;
            }
            else if(y[j] > x[i]) {
                sum+= (y[j]*v);
                h+=1;
                j--;
            }
            else {
                if(h>v) {
                    sum+= (y[j]*v);
                    h+=1;
                     j--;
                }
                else {
                    sum  += (x[i] * h);
                    v+=1;
                    i--;
                }
            }
            
            //System.out.println(sum + " = " + h + " " + v);
            
            totalsum+=sum;
            
        }
        
        while(i>=0) {
            totalsum+=(x[i]*h);
            v+=1;
            i--;
        }
        
        while(j>=0) {
            totalsum+=(y[j]*v);
            h+=1;
            j--;
        }
        
        return totalsum;
    }
}
