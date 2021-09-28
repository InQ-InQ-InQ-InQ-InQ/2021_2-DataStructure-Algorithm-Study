#include <cstdio>
#include <queue>

using namespace std;

char map[102][102];
int n, m;

void BFS(int x, int y)
{
    int ch[101][101] = { 0 };
    char dx[] = { 1, 0, -1, 0 }; // 3시, 6시, 9시, 12시 x좌표를 가리킴
    char dy[] = { 0, 1, 0, -1 }; // 3시, 6시, 9시, 12시 y좌표를 가리킴
    queue<pair<int, int>> q;

    ch[x][y] = 1;
    q.push({ x, y });

    while (!q.empty()) {
        int px = q.front().first;
        int py = q.front().second;
        q.pop();

        // 3시, 6시, 9시, 12시 순으로 경로를 탐색
        for (int i = 0; i < 4; i++) {
            int xx = px + dx[i];
            int yy = py + dy[i];

            // (n, m)에 도착하면 이동한 칸 수를 출력하고 종료
            if (xx == n && yy == m) {
                printf("%d\n", ch[px][py] + 1);
                return;
            }

            // 방문하지 않은 길(0)일 경우 해당 좌표에 이동한 칸 수를 기록하고
            // 다음 탐색을 위해 큐에 삽입
            if (map[xx][yy] == '1' && ch[xx][yy] == 0) {
                ch[xx][yy] = ch[px][py] + 1;
                q.push({ xx, yy });
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
    
    BFS(1, 1);

    return 0;
}