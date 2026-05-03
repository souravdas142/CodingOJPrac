class Solution {
    public int sumOfPrimesInRange(int n) {
        if(n<2) return 0;
        int x = 0;
        int t = n;
        while(t!=0) {
            x*=10;
            int p = t%10;
            x=(x+p);
            t/=10;
            
        }

        
        int low = Math.min(x,n);
        int high = Math.max(x,n);
        
        int ans = solve(low,high);
        
        return ans;
        
    }
    public int[] seive(int low) {
        boolean[] seived = new boolean[low+1];
        int cnt = low;
        for(int i = 0;i<=low;i++) seived[i]=true;
        
        seived[0] = false;
        seived[1] = false;
        

        for(int i = 4;i<=low;i+=2) {
            seived[i] = false;
            cnt--;
        }
        
        cnt-=1;
        
        for(int i = 3;i*i<=low;i+=2) {
            if(seived[i]==false) continue;
            for(int j = i*i;j<=low;j+=(i*2)) {
                if(seived[j]==true) {
                    seived[j]=false;
                    cnt--;
                }
            }
        }

        int[] ans = new int[cnt];
        ans[0] = 2;
        int j = 1;
        for(int i = 3;i*i<=low;i++) {
            if(seived[i]==true)
                ans[j++]=i;
        }

        return ans;
        
    }
    public int solve(int low, int high) {

        
        int[] preSieve;
        int ans = 0;

        // if(low<2) {
        //     preSieve = seive(high);
        //     for(int e: preSieve) ans+=e;
        //     return ans;
        // }
        
        preSieve  = seive(high);
        
                      
        int n = preSieve.length;

        // for(int k: preSieve) {
        //     System.out.print(k+" , ");
        // }
        // System.out.println();
        
        boolean[] finala = new boolean[high-low+1];
        int p = high-low+1;
        for(int i = 0;i<p;i++) finala[i] = true;
        
        for(int i = 0;i<n;i++) {
            if(preSieve[i]==0) break;
            int x = (low/preSieve[i])*preSieve[i];
            if(x==preSieve[i]) x+=preSieve[i];
            
            while(x<=high) {
                if(x>=low && x!=preSieve[i]) {
                    finala[x-low]=false;
                }
                x+=preSieve[i];
                
            }
        }

        for(int i =0;i<p;i++) {
            if(finala[i]==true && (i+low)>1)
                ans+=(i+low);
        }
        //System.out.println();

        return ans;
    }
}