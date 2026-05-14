class Solution {
    public double fractionalKnapsack(int[] val, int[] wt, int capacity) {
        // code here
        ArrayList<int[]> arr = new ArrayList<>();
        int n = val.length;
        
        for(int i = 0;i<n;i++) {
            arr.add(new int[]{val[i],wt[i]});
        }
        
        Collections.sort(arr,(a,b)->{
            double uval1 = ((double)a[0])/((double)a[1]);
            double uval2 = ((double)b[0])/((double)b[1]);
            return Double.compare(uval2,uval1);
        });
        
        // for(int i = 0;i<n;i++) {
        //     System.out.println(arr.get(i)[0] + " "+arr.get(i)[1]);
        // }
        
        double ans = 0.0f;
        for(int i = 0;i<n;i++) {
            if(capacity<=0) break;
            double uval1 = ((double)arr.get(i)[0])/((double)arr.get(i)[1]);
            int x = Math.min(capacity,arr.get(i)[1]);
         //   System.out.println(x);
            ans+=(x*uval1);
            capacity-=x;
        }
        
        
        
        return ans;
        
    }
}