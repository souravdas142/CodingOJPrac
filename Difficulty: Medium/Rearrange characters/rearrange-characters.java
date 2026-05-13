class Solution {
    public static String rearrangeString(String s) {
        // code here
                
               

        int n = s.length();
        StringBuilder sb = new StringBuilder();
        for(int i = 0;i<n;i++) sb.append(" ");
        ArrayList<int[]> arr = new ArrayList<>();
        
        
        
        int[] freq = new int[26];
        for(int i = 0;i<n;i++) freq[s.charAt(i)-'a']++;
        for(int i = 0;i<26;i++) {
            if(freq[i]>0) arr.add(new int[]{freq[i],i});
        }
        
        Collections.sort(arr,(a,b)->{
            return Integer.compare(b[0], a[0]);
        });
        
        // for(int[] a: arr) {
        //     System.out.println(a[0]+" = "+a[1]);
        // }

        int m = arr.size();
        int i = 0;
        int j = 0;
        int p = sb.length();
        //  if(n==p) {
        //     System.out.println(p);
        //  }
         //       System.out.println("ok");
       if(arr.get(0)[0]>(n+1)/2) return "";
        while(i<n && j<m) {
            int[] cur = arr.get(j);

            while(i<n && cur[0]>0) {
                
                sb.setCharAt(i,(char)(cur[1]+'a'));
                    
             // System.out.println(sb.toString());
                cur[0]--;

                
                i+=2;
                
                if(i>=n) {
                    i=1;
                    
                }
                
            }

            //if(cur[0]>0) return "";
            
            j++;
            
        }
                    
            
        return sb.toString();
    }
}