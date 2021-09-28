import java.util.*;

public class Solution {
    //큐를 활용한 BFS
    //시작 정점으로부터 거리가 가까운 정점의 순서로 탐색
    //그래프 탐색의 경우 어떤 노드를 방문했는지 검사 (무한루프 방지)
    //재귀동작 X
    //차례로 저장할 수 있는 큐 사용
    //선입선출 원칙 탐색
    public static void bfs_array(int v, int[][] adjArray, boolean[] visited) {
        Queue<Integer> q = new LinkedList<>();
        int n = adjArray.length - 1;

        q.add(v); //시작정점 인큐
        visited[v] = true; //시작 정점 방문으로 기록
        while (!q.isEmpty()) {
            v = q.poll(); //시작정점 디큐
            System.out.print(v + " ");
            //현재정점, 닿아있는 정점 확인 + 방문안했는지 확인
            for (int i = 1; i <= n; i++) {
                if (adjArray[v][i] == 1 && !visited[i]) {
                    q.add(i);
                    visited[i] = true;
                }
            }
        }
    }

    //재귀를 활용한 DFS
    //자기 자신을 호출하는 순환 알고리즘의 형태
    //어떤 노드를 방문했었는지 여부 검사 (무한루프 방지)
    public static void dfs_array(int v, int[][] adjArray, boolean[] visited) {
        int len = adjArray.length - 1;
        visited[v] = true;
        System.out.print(v + " ");
        //현재정점, 닿아있는 정점 확인 + 방문안했는지 확인
        for (int i = 1; i <= len; i++)
            if (adjArray[v][i] == 1 && !visited[i]) {
                dfs_array(i, adjArray, visited);
            }
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt(); //정점의 개수
        int m = scan.nextInt(); //간선의 개수
        int v = scan.nextInt(); //탐색을 시작할 정점의 번호

        boolean visted[] = new boolean[n + 1]; //0이 아니라 1부터 시작해서 +1해줌

        int[][] adjArray = new int[n + 1][n + 1];

        //간선은 양방향, 여러개 가능
        for (int i = 0; i < m; i++) {
            int v1 = scan.nextInt();
            int v2 = scan.nextInt();

            adjArray[v1][v2] = 1;
            adjArray[v2][v1] = 1;
        }
        dfs_array(v, adjArray, visted);
        Arrays.fill(visted, false); //방문기록 초기화
        System.out.println();
        bfs_array(v, adjArray, visted);
    }

}