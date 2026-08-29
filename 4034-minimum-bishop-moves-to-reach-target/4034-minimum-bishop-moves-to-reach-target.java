class Solution {
    public int minBishopMoves(int[] source, int[] target) {
        int sr = source[0];
        int sc = source[1];
        int tr = target[0];
        int tc = target[1];

        int src1 = Math.abs(sr-sc);
        int src2 = Math.abs(sr+sc);

        int trc1 = Math.abs(tr-tc);
        int trc2 = Math.abs(tr+tc);

        if(src1%2 != trc1%2 || src2%2 != trc2%2) return -1;

        if(sr+sc == tr+tc || sr-sc == tr-tc) return 1;

        return 2;
        
        
    }
}