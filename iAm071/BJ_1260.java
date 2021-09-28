package BJ_1260;
import java.util.*;

public class BJ_1260 {
	static int n,m,s;
	static int[][] connect;
	static boolean[] visited;
	
	private static void dfs(int i) {
		visited[i] = true;
		System.out.print(i + " ");
		
		for(int j=1;j<n+1;j++) {
			if(connect[i][j] == 1 && visited[j] == false)
				dfs(j);
		}
	}
	
	private static void bfs(int i) {
		Queue<Integer> queue = new LinkedList<>();
		queue.offer(i);
		visited[i] = true;
		
		while(!queue.isEmpty()) {
			int temp = queue.poll();
			System.out.print(temp + " ");
			
			for(int j=1;j<n+1;j++) {
				if(connect[temp][j] == 1 && visited[j] == false) {
					queue.offer(j);
					visited[j] = true;
				}
			}
		}
	}
	
    public static void main(String[] args) {
    	Scanner sc = new Scanner(System.in);
    	n = sc.nextInt();
    	m = sc.nextInt();
    	s = sc.nextInt();
    	
    	connect = new int[n+1][n+1];
    	
    	for(int i=0;i<m;i++) {
    		int a = sc.nextInt();
    		int b = sc.nextInt();
    		
    		connect[a][b] = connect[b][a] = 1;
    	}
    	
    	visited = new boolean[n+1];
    	dfs(s);
    	
    	System.out.println();
    	
    	visited = new boolean[n+1];
    	bfs(s);
    	
    	sc.close();
    }
}