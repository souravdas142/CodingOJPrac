class Solution {

    public void dfs(String beginWord, String endWord, 
                    Map<String,Integer> dist, List<List<String>> ans,
                    List<String> anslist) {

        if(beginWord.equals(endWord)) {
            ArrayList<String> tmp = new ArrayList<>(anslist);
            Collections.reverse(tmp);
            ans.add(tmp);
            return;
        }

        int level = dist.get(beginWord);

        int n = beginWord.length();

        for(int i = 0;i<n;i++) {
            StringBuilder sb = new StringBuilder(beginWord);
            
            for(char ch='a';ch<='z';ch++) {
                if(ch==beginWord.charAt(i)) continue;
                sb.setCharAt(i,ch);
                String modString = sb.toString();
                int levelDist = dist.getOrDefault(modString,-1);
                if(level-levelDist==1) {
                    anslist.add(modString);
                    dfs(modString,endWord,dist,ans,anslist);
                    anslist.remove(modString);
                }
            }

            sb.setCharAt(i,beginWord.charAt(i));
        }
        

    }

    public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {

        List<List<String>> ans = new ArrayList<>();
        Set<String> wordSet = new HashSet<>();
        Map<String,Integer> dist = new HashMap<>();
        for(String s: wordList) wordSet.add(s);
        if(wordSet.contains(endWord)==false) return ans;
        int level = ladderLength(beginWord,endWord,wordList,dist);
        List<String> anslist = new ArrayList<>();
        anslist.add(endWord);

        dfs(endWord,beginWord,dist,ans,anslist);

        return ans;
        
    }

     public int ladderLength(String beginWord, String endWord, List<String> wordList, Map<String,Integer> dist) {
       
        // Map<String,Integer> dist = new HashMap<>();

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