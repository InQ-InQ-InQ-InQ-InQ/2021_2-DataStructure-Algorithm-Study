#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int ch[1001];
vector<int> map[1001];

void DFS(int v);
void BFS(int v);

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, v;

    cin >> n >> m >> v;
    // 간선 정보 입력
    for (int i = 0; i < m; i++) {
        int a, b;

        cin >> a >> b;
        map[a].push_back(b);
        map[b].push_back(a);
    }

    // 간선 정보 오름차순 정렬
    for (int i = 1; i <= n; i++) {
        sort(map[i].begin(), map[i].end());
    }
    
    // DFS
    ch[v] = 1;
    DFS(v);
    cout << "\n";

    // 방문한 노드 초기화
    for (int i = 1; i <= n; i++) {
        ch[i] = 0;
    }

    // BFS
    BFS(v);

    return 0;
}

void DFS(int v)
{
    cout << v << " ";
    for (int i = 0; i < map[v].size(); i++) {
        if (ch[map[v][i]] == 0) {
            ch[map[v][i]] = 1;
            DFS(map[v][i]);
        }
    }
}

void BFS(int v)
{
    queue<int> q;

    ch[v] = 1;
    q.push(v);

    while (!q.empty()) {
        int x;
        
        x = q.front();
        q.pop();
        cout << x << " ";

        for (int i = 0; i < map[x].size(); i++) {
            if (ch[map[x][i]] == 0) {
                ch[map[x][i]] = 1;
                q.push(map[x][i]);
            }
        }
    }
    cout << "\n";
}