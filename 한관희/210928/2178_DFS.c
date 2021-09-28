#include <stdio.h>

char map[101][101];
char dx[] = { 1, 0, -1, 0 }; // 3��, 6��, 9��, 12�� x��ǥ�� ����Ŵ
char dy[] = { 0, 1, 0, -1 }; // 3��, 6��, 9��, 12�� y��ǥ�� ����Ŵ
int n, m;
int min = 2147483647; // (n, m)������ �̵� ĭ ���� ����

void DFS(int x, int y, int cnt)
{
    if (x == n && y == m) {
        if (cnt < min) min = cnt;
    }
    else {
        // 3��, 6��, 9��, 12�� ������ ��� Ž��
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            
            // �̷��� ������ ��� ��� �ǳʶ�
            if (xx < 1 || xx > n || yy < 1 || yy > m)
                continue;
            
            // �湮�� �� ���� ��('1')�� ��� �湮����('2')���� ǥ��, �湮�� ������ �ٽ� '1'�� ����
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
    // n * m ũ���� �̷θ� �Է�
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf(" %c", &map[i][j]);
        }
    }

    // (1, 1)�� �湮����('2')�� ǥ��
    map[1][1] = '2';
    DFS(1, 1, 1);

    printf("%d\n", min);

    return 0;
}