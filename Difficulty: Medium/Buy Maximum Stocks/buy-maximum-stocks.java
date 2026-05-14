class Solution {
    public static int buyMaximumProducts(int k, int[] price) {
        // code here
        
        ArrayList<int[]> arr = new ArrayList<>();
        int n = price.length;
        for(int i = 0;i<n;i++) {
            arr.add(new int[]{price[i],i+1});
        }
        Collections.sort(arr,(a,b)->{
            return Integer.compare(a[0],b[0]);
        });
        int cnt= 0;
        for(int i = 0;i<n;i++) {
            if(k<arr.get(i)[0]) break;
            int x = Math.min(k/arr.get(i)[0],arr.get(i)[1]);
            k -= (x*arr.get(i)[0]);
            if(x>0)
                cnt+=x;
            
        }
        
        return cnt;
        
    }
}
