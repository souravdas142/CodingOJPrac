
class Solution {
    public String smallestNumber(int s, int d) {
        // code here
        StringBuilder sb = new StringBuilder();
        for(int i = 0;i<=d;i++) {
            sb.append(" ");
        }
        
        while(d>1) {
            boolean flag = false;
            for(int i = 9;i>=0;i--) {
                if(s-i>=1) {
                    sb.setCharAt(d,(char)('0'+i));
                    s-=i;
                    flag = true;
                    break;
                }
            }
            if(flag==false) sb.setCharAt(d,'0');
            
            d--;
        }
        if(s>=10) return "-1";
        sb.setCharAt(d,(char)('0'+s));
        
        return sb.substring(1);
    }
}
