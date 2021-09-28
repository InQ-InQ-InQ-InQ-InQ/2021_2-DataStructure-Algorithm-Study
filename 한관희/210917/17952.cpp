#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int flag, a, t;
    int total = 0;
    stack<pair<int, int>> stk;

    cin >> n;
    while (n--) {
        cin >> flag;
        if (flag == 1) { // 첫 입력에 '1'이 들어오면 a, t를 스택에 넣음
            cin >> a >> t;
            stk.push({a, t});
        }

        if (!stk.empty()) { // 매 초 최근에 push한 데이터의 t를 1씩 차감
            stk.top().second--;
            if (stk.top().second == 0) { // t가 0이 되면 과제 완료 -> pop, 점수 반영
                total += stk.top().first;
                stk.pop();
            }
        }
    }
    cout << total << "\n";

    return 0;
}