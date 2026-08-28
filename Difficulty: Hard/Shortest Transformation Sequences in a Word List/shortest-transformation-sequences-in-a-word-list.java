class Solution {
    public ArrayList<ArrayList<String>> findSequences(String[] wordList, String beginWord,
                                                      String endWord) {
        // code here
        
        
        ArrayList<ArrayList<String>> ans = new ArrayList<>();

        Set<String> wordSet = new HashSet<>();
        for(String s: wordList) wordSet.add(s);
        if(wordSet.contains(endWord)==false) return ans;

        Queue<ArrayList<String>> q = new LinkedList<>();

        int endWordMark = -1;
        q.add(new ArrayList<>(List.of(beginWord)));
        int level = 0;

        while(q.isEmpty()==false) {

            ArrayList<String> front = q.poll();

            String s = front.get(front.size()-1);

             wordSet.remove(s);

            if(front.size()>level) {
                level++;
            }

            if(level==endWordMark) {
                if(s.equals(endWord))
                    ans.add(front);
                continue;
            }

            StringBuilder sb = new StringBuilder(s);
            int d = s.length();
            for(int i = 0;i<d;i++) {
                char reserv = sb.charAt(i);
                for(char ch = 'a';ch<='z';ch++) {
                    if(ch==reserv) continue;
                    sb.setCharAt(i,ch);
                    String modWord = sb.toString();
                    if(wordSet.contains(modWord)) {
                        ArrayList<String> temp = new ArrayList<>(front);
                        temp.add(modWord);
                        if(modWord.equals(endWord) && endWordMark==-1) endWordMark = temp.size();

                        q.add(temp);
                    }
                }
                sb.setCharAt(i,reserv);
            }

        }

        return ans;
        
    }
}



// class Solution {
//     public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {

//         ArrayList<ArrayList<String>> ans = new ArrayList<>();

//         Set<String> wordSet = new HashSet<>();
//         for(String s: wordList) wordSet.add(s);
//         if(wordSet.contains(endWord)==false) return ans;

//         Queue<ArrayList<String>> q = new LinkedList<>();

//         int endWordMark = -1;
//         q.add(new ArrayList<>(List.of(beginWord)));
//         int level = 0;

//         while(q.isEmpty()==false) {

//             ArrayList<String> front = q.poll();

//             String s = front.get(front.size()-1);

//              wordSet.remove(s);

//             if(front.size()>level) {
//                 level++;
//             }

//             if(level==endWordMark) {
//                 if(s.equals(endWord))
//                     ans.add(front);
//                 continue;
//             }

//             StringBuilder sb = new StringBuilder(s);
//             int d = s.length();
//             for(int i = 0;i<d;i++) {
//                 char reserv = sb.charAt(i);
//                 for(char ch = 'a';ch<='z';ch++) {
//                     if(ch==reserv) continue;
//                     sb.setCharAt(i,ch);
//                     String modWord = sb.toString();
//                     if(wordSet.contains(modWord)) {
//                         ArrayList<String> temp = new ArrayList<>(front);
//                         temp.add(modWord);
//                         if(modWord.equals(endWord) && endWordMark==-1) endWordMark = temp.size();

//                         q.add(temp);
//                     }
//                 }
//                 sb.setCharAt(i,reserv);
//             }

//         }

//         return ans;
//     }
// }