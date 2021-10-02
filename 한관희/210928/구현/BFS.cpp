#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    // BFS.txt의 내용을 입력 버퍼에 읽어옴
    freopen("BFS.txt", "rt", stdin);
    
    char ch[10] = { 0 };
    int a, b, x;
    queue<int> q;
    vector<int> map[10];

    // 간선 정보를 읽어 a와 b를 연결(양방향)
    for (int i = 1; i <= 6; i++) {
        scanf("%d %d", &a, &b);
        map[a].push_back(b);
        map[b].push_back(a);
    }

    // 루트 노드를 큐에 넣고 방문함을 표시
    q.push(1);
    ch[1] = 1;

    // 큐가 빌 때까지(너비 탐색을 완료할 때까지) 수행
    while (!q.empty()) {
        // x에 큐의 front값을 읽어옴
        x = q.front();
        q.pop();
        printf("%d ", x);
        // x와 연결된 모든 노드를 큐에 넣고 방문함을 표시
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