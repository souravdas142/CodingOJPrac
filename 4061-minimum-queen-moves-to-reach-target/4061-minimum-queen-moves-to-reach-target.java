class Solution {
    public int minQueenMoves(int[] src, int[] target) {
        if(src[0]==target[0] && src[1]==target[1]) return 0;
        if(src[0]==target[0] || src[1]==target[1]) return 1;

        

        int parity1  = Math.abs(src[0]-src[1]);
        int parity2 = Math.abs(target[0]-target[1]);

        if((src[0]+src[1] == target[0]+target[1]) || (src[0]-src[1] == target[0]-target[1])) return 1;
       return 2;

    }
}