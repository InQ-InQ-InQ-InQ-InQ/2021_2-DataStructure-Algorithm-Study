#include <stdio.h>

char map[101][101];
char dx[] = { 1, 0, -1, 0 }; // 3시, 6시, 9시, 12시 x좌표를 가리킴
char dy[] = { 0, 1, 0, -1 }; // 3시, 6시, 9시, 12시 y좌표를 가리킴
int n, m;
int min = 2147483647; // (n, m)까지의 이동 칸 수를 저장

void DFS(int x, int y, int cnt)
{
    if (x == n && y == m) {
        if (cnt < min) min = cnt;
    }
    else {
        // 3시, 6시, 9시, 12시 순으로 경로 탐색
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            
            // 미로의 범위를 벗어날 경우 건너뜀
            if (xx < 1 || xx > n || yy < 1 || yy > m)
                continue;
            
            // 방문한 적 없는 길('1')일 경우 방문했음('2')으로 표시, 방문이 끝나면 다시 '1'로 변경
            if (map[xx][yy] == '1') {
                map[xx][yy] = '2';
                DFS(xx, yy, cnt + 1);
                map[xx][yy] = '1';
            }
        }
    }
}

int main()
{
    // n * m 크기의 미로를 입력
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf(" %c", &map[i][j]);
        }
    }

    // (1, 1)에 방문했음('2')을 표시
    map[1][1] = '2';
    DFS(1, 1, 1);

    printf("%d\n", min);

    return 0;
}