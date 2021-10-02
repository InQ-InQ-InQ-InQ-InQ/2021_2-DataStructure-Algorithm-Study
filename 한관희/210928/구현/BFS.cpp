#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    // BFS.txt�� ������ �Է� ���ۿ� �о��
    freopen("BFS.txt", "rt", stdin);
    
    char ch[10] = { 0 };
    int a, b, x;
    queue<int> q;
    vector<int> map[10];

    // ���� ������ �о� a�� b�� ����(�����)
    for (int i = 1; i <= 6; i++) {
        scanf("%d %d", &a, &b);
        map[a].push_back(b);
        map[b].push_back(a);
    }

    // ��Ʈ ��带 ť�� �ְ� �湮���� ǥ��
    q.push(1);
    ch[1] = 1;

    // ť�� �� ������(�ʺ� Ž���� �Ϸ��� ������) ����
    while (!q.empty()) {
        // x�� ť�� front���� �о��
        x = q.front();
        q.pop();
        printf("%d ", x);
        // x�� ����� ��� ��带 ť�� �ְ� �湮���� ǥ��
        for (int i = 0; i < map[x].size(); i++) {
            if (ch[map[x][i]] == 0) {
                ch[map[x][i]] = 1;
                q.push(map[x][i]);
            }
        }
    }
    putchar('\n');

    return 0;
}