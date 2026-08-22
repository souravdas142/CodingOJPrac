
class Pair {
    public String first;
    public int second;
    public Pair(String s, int d) {
        first = s;
        second = d;
    }
}

class Solution {


    

    public int ladderLength(String beginWord, String endWord, List<String> wordList) {

        Set<String> words = new HashSet<>();

        Set<String> visited = new HashSet<>();

        for(String s: wordList) words.add(s);

        Queue<Pair> que = new ArrayDeque<>();

        int n = beginWord.length();

        que.add(new Pair(beginWord,1));
        visited.add(beginWord);

        while(que.isEmpty()==false) {
            Pair node = que.poll();

            // if(node.first.toString().equals(endWord)) {
            //     return node.second;
            // }
            StringBuilder bword = new StringBuilder(node.first);
             System.out.print(bword.toString()+" -> ");
            int dist = node.second;
            for(int i = 0;i<n;i++ ) {
                char res = bword.charAt(i);
                for(char ch = 'a';ch<='z';ch++) {
                    if(res==ch) continue;
                    bword.setCharAt(i,ch);
                    String bwords = bword.toString();
                    if(words.contains(bwords)==true && visited.contains(bwords)==false) {

                       

                        if(bwords.equals(endWord)) {
                            return dist+1;
                        }
                        
                        que.add(new Pair(bwords,dist+1));
                        visited.add(bwords);
                        
                    }
                }

                bword.setCharAt(i,res);

            }

        }

        return 0;

    }
}