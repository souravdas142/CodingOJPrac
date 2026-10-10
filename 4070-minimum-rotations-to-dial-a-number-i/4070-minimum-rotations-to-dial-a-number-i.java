class Solution {
    public int minRotations(String s) {
        int n = s.length();
        int ans = 0;
        int cur = 0;
        
        for(int i = 0;i<n;i++) {
            int target = s.charAt(i)-'0';
            //System.out.print(cur+" -> "+target+" = ");
            if(cur!=target) {
                int left = (target<cur)?cur-target:9-target+cur+1;
                int right = (target>cur)?target-cur: 9-cur+target+1;
                cur = target;
                int x=Math.min(left,right);
                // System.out.println(x);
                ans+=x;
            }
           
        }

        return ans;
    }
}