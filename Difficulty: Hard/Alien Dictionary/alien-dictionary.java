class Solution {
	
	
	public void constructAdjlist(String[] words, ArrayList<Set<Integer>> adjlist) {
		
		int n = words.length;
		for (int i = 1; i<n; i++) {
			String s1 = words[i - 1];
			
			String s2 = words[i];
			
			int m = Math.min(s1.length(), s2.length());
			
			for (int k = 0; k<m; k++) {
				if (s1.charAt(k) != s2.charAt(k)) {
					int u = s1.charAt(k) - 'a';
					int v = s2.charAt(k) - 'a';
					// System.out.print(u+" -> "+v+", ");
					adjlist.get(u).add(v);
					break;
				}
			}
			
			
		}
		
	}
	
	public String findOrder(String[] words) {
		// code here
		ArrayList<Set<Integer>> adjlist = new ArrayList<>();
		for (int i = 0; i<26; i++)
			adjlist.add(new HashSet<Integer>());
		
		int n = words.length;
		int[] indeg = new int[26];
		
		Arrays.fill(indeg, -1);
		
		for (int i = 0; i<n; i++) {
			int m = words[i].length();
			for (int j = 0; j<m; j++) {
				indeg[words[i].charAt(j) - 'a'] = 0;
			}
		}
		
		constructAdjlist(words, adjlist);
		
		for (int u = 0; u<26; u++) {
			
			for (Integer v: adjlist.get(u)) {
				indeg[v] = (indeg[v] == -1)?1:indeg[v]+1;
			}
		}
		
		Queue<Integer> que = new ArrayDeque<>();
		
		int total = 0;
		
		for (int i = 0; i<26; i++) {
			if (indeg[i] == 0) {
				que.add(i);
			}
			if (indeg[i] >= 0)
				total++;
		}
		
		/// int ans = 0;
		
		StringBuilder ans = new StringBuilder();
		
		while (!que.isEmpty()) {
			int u = que.poll();
			ans.append((char)('a' + u));
			for (Integer v: adjlist.get(u)) {
				indeg[v]--;
				if (indeg[v] == 0) {
					que.add(v);
				}
			}
		}
		
		// System.out.println(ans+", "+total);
		
		if (ans.length() != total)
			return "";
		
		// return "true";
		
		// System.out.println(ans.toString());
		return (ans.toString());
	}
}
