#include <cstdio>
#include <queue>

using namespace std;

char map[102][102];
int n, m;

void BFS(int x, int y)
{
    int ch[101][101] = { 0 };
    char dx[] = { 1, 0, -1, 0 }; // 3��, 6��, 9��, 12�� x��ǥ�� ����Ŵ
    char dy[] = { 0, 1, 0, -1 }; // 3��, 6��, 9��, 12�� y��ǥ�� ����Ŵ
    queue<pair<int, int>> q;

    ch[x][y] = 1;
    q.push({ x, y });

    while (!q.empty()) {
        int px = q.front().first;
        int py = q.front().second;
        q.pop();

        // 3��, 6��, 9��, 12�� ������ ��θ� Ž��
        for (int i = 0; i < 4; i++) {
            int xx = px + dx[i];
            int yy = py + dy[i];

            // (n, m)�� �����ϸ� �̵��� ĭ ���� ����ϰ� ����
            if (xx == n && yy == m) {
                printf("%d\n", ch[px][py] + 1);
                return;
            }

            // �湮���� ���� ��(0)�� ��� �ش� ��ǥ�� �̵��� ĭ ���� ����ϰ�
            // ���� Ž���� ���� ť�� ����
            if (map[xx][yy] == '1' && ch[xx][yy] == 0) {
                ch[xx][yy] = ch[px][py] + 1;
                q.push({ xx, yy });
            }
        }
    }
}

int main()
{
    // n * m ũ���� �̷θ� �Է�
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf(" %c", &map[i][j]);
        }
    }
    
    BFS(1, 1);

    return 0;
}