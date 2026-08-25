class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        // Set<String> wordsmp = new HasSet<>();
        // Set<String> visited = new HasSet<>();
        Map<String,Integer> dist = new HashMap<>();


        for(String s: wordList) dist.put(s,Integer.MAX_VALUE);
        
        
        if(dist.containsKey(endWord)==false) return 0;

        Queue<String> que = new ArrayDeque<>();
        que.add(beginWord);
        dist.put(beginWord,1);

        while(!que.isEmpty()) {
            StringBuilder u = new StringBuilder(que.poll());
            String ustr = u.toString();

            int sn = u.length();
            for(int i = 0;i<sn;i++) {
                
                char reserv = u.charAt(i);

                for(char ch='a';ch<='z';ch++) {
                    if(ch==reserv) continue;
                    u.setCharAt(i,ch);
                    String v = u.toString();
                    if(dist.containsKey(v)==true && dist.get(v)==Integer.MAX_VALUE) {
                        dist.put(v,dist.get(ustr)+1);
                        if(v.equals(endWord)==true) {
                            return dist.get(v);
                        }
                        que.add(v);
                    }
                }

                u.setCharAt(i,reserv);
            }
        }

        return 0;
    }
}